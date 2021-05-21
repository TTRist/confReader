#include <iostream>
#include "confReader.hpp"
using namespace std;


int main(){
    ifstream infile("sample.txt"); // 外部データ読み込み
    string separator = conf::setSeparetor(",","=","\\s"); // 区切り文字設定(正規表現)
    if(infile) conf::setMap(conf::config_map, infile, separator); // 外部ファイルからキーと値を登録
    else cout << "読み込み失敗\n";
    
    // 出力例(以下の5つの型に対応)
    cout << conf::config_map["ID"] << endl; // string型で出力：1
    string str   = conf::readMap("COMPORT"); cout << str   << endl; // 出力値：COM3
    int    num_i = conf::readMap("ID");      cout << num_i << endl; // 出力値：1
    long   num_l = conf::readMap("LIMIT");   cout << num_l << endl; // 出力値：123456789
    float  num_f = conf::readMap("SPEED");   cout << num_f << endl; // 出力値：12.3
    double num_d = conf::readMap("ACCEL");   cout << num_d << endl; // 出力値：4.56
    
}

