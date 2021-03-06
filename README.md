# phonetic

Phonetic recognition using SVM & MFCC

[![Build Status](https://travis-ci.org/hiroyam/phonetic.svg?branch=master)](https://travis-ci.org/hiroyam/phonetic)

---

#### これは何？

MFCCとSVMで音声認識してみた実験コードです。全てC++によるフルスクラッチです。


#### 実験

話者3人の音声データで訓練し、以下の音声認識を実験してみました。
- 音素識別: あいうえおの5クラスに分類
- 話者識別: ゆかり・マキマキ・茜の3クラスに分類

SVMは2クラス分類器のため、nC2個の分類器を用いて1vs1で多クラス分類しました。  
用意したデータでは 90% 程度の accuracy でした。

MFCCは12次元ベクトルのためそのままではプロットできません。  
そこで主成分分析で2次元に削減し、プロットしてみました。


##### 話者別
![](images/plot_who.png)


##### あいうえお別
![](images/plot_what.png)

