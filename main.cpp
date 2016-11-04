#include "./util.hpp"

using namespace cc;

#include "./wav.hpp"
#include "./parser.hpp"
#include "./matrix.hpp"
#include "./classifier.hpp"

int main(int argc, char *argv[]) {
    try {
        // データのファイルリストを取得する
        std::vector<std::string> train_fn,    test_fn;
        std::vector<vec_t>       train_data,  test_data;
        std::vector<int>         train_label, test_label;
        parser::csv::read_fn("./train.csv", train_fn, train_data, train_label);
        parser::csv::read_fn("./test.csv",  test_fn,  test_data,  test_label);

        // MFCCを計算する
#pragma omp parallel for
        for (size_t i = 0; i < train_fn.size(); i++) wav::mfcc(train_fn[i], train_data[i]);

#pragma omp parallel for
        for (size_t i = 0; i < test_fn.size(); i++) wav::mfcc(test_fn[i], test_data[i]);

        // クラス数を調べる
        int n_class = *max_element(train_label.begin(), train_label.end()) + 1;

        // 1vs1でSVMを学習する
        std::vector<classifier::binary::svm> classifiers;
        classifier::multiclass::fit_1vs1(n_class, classifiers, train_data, train_label);

        // 1vs1で予測する
        for (size_t i = 0; i < test_data.size(); i++) {
            int p = classifier::multiclass::predict_1vs1(n_class, classifiers, test_data[i]);
			if (p == test_label[i]) {
                std::cout << colorant('g', format_str("predict=%d, label=%d", p, test_label[i])) << std::endl;
            } else {
                std::cout << colorant('r', format_str("predict=%d, label=%d", p, test_label[i])) << std::endl;
            }
        }

        // 主成分分析してみる
        std::vector<vec_t> flatten;
        matrix::pca(train_data, flatten);

        // プロットする
        std::ofstream ofs("output");
        for (size_t i = 0; i < flatten.size(); i++) {
            ofs << format_str("%f %f %d", flatten[i][0], flatten[i][1], train_label[i]) << std::endl;
        }

    } catch (const std::exception &e) {
        std::cerr << colorant('y', format_str("error: %s", e.what())) << std::endl;
    }
}

