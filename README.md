# confReader
c++でsplit関数とかが使える＆外部ファイルのキーと要素を登録できるライブラリ

## 設定ファイルの書き方
同梱のsample.txtで察してください．(キー=値)
区切り文字は自由に設定可能．
sample.cppの場合は「,」「=」「空白文字」に対応．


## 使い方
同梱のsample.cppで察してください．
一応下に説明かく．

### ファイル読みこみ
読み込みミスを考慮しなければ以下のコードで読み込みできる．
setMap 関数でキーと値を対応させてる．
~~~
ifstream infile("hoge.txt");
if(infile) conf::setMap(conf::config_map, infile, "区切り文字");
~~~
conf::config_mapにはstring型でキーと値が登録される．
別に好きな型のmapにいれたいなら自分で作ったやつを引数にして.


#### 区切り文字
setSeparretor関数で複数種の区切り文字を設定できるけど，
正直 R"(=|,|\s)" のような生文字列リテラル書くのがいいと思う．
|で区切り文字を分けてるから，区切り文字として|は使用不可．

### データの使用方法
string型なのでintにするならstoi関数などでやればOK．
int a = stoi(conf::config_map["キー"])

ただ毎回それをするのはめんどいので readMap("キー") 関数で自動的に型を判別できる．
現状の対応型：string,char*,short,int,long,float,double
必要になったら順次追加すればいいと思ってる

## split関数
外部ファイルを読み込むけど，mapにする必要がない場合で，
区切り文字で文字列を区切りたいならこの関数だけ使えばいい．
