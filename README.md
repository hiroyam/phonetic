# phonetic

Phonetic recognition using SVM & MFCC

[![Build Status](https://travis-ci.org/hiroyam/phonetic.svg?branch=master)](https://travis-ci.org/hiroyam/phonetic)

---

#### これは何？

MFCCとSVMで音声認識してみた実験コードです。全てC++によるフルスクラッチです。


#### 実験

ゆかり・マキ・茜3人の音声データで訓練し、以下の音声認識をしてみました。
- 音素識別: あいうえおの5クラスに分類
- 話者識別: ゆかり・マキ・茜の3クラスに分類

色々なデータで試しましたが、accuracy は 90% 程度でした。


#### 主成分分析

MFCCは12次元ベクトルのためそのままではプロットできません。
そこで主成分分析で2次元に潰し、プロットしてみました。


##### 話者別
![](images/plot_who.png)


##### あいうえお別
![](images/plot_what.png)



