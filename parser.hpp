namespace parser {
namespace csv {
void read_fn(std::string               fn,
             std::vector<std::string> &filename,
             std::vector<vec_t>       &data,
             std::vector<int>         &label) {
    std::string   s;
    std::ifstream ifs(fn);
    while (std::getline(ifs, s)) {
        std::string        t;
        std::istringstream iss(s);

        // read x
        std::getline(iss, t, ',');
        filename.push_back(t);

        // allocate data
        vec_t v;
        data.push_back(v);

        // read label
        std::getline(iss, t, ',');
        label.push_back(std::stoi(t));
    }
}

// void read_iris(std::string fn, std::vector<vec_t> &data, std::vector<int> &label) {
//     std::string   s;
//     std::ifstream ifs(fn);
//     while (std::getline(ifs, s)) {
//         vec_t              v;
//         std::string        t;
//         std::istringstream iss(s);
//
//         // read x
//         std::getline(iss, t, ',');
//         v.push_back(std::stof(t));
//
//         // read y
//         std::getline(iss, t, ',');
//         v.push_back(std::stof(t));
//         data.push_back(v);
//
//         // read label
//         std::getline(iss, t, ',');
//         label.push_back(std::stoi(t));
//     }
// }

} // namespace csv
} // namespace parser
