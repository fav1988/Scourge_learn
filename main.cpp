#include <iostream>
#include <string>
#include <map>
#include <fstream>

using namespace std;

int main()
{
  map <string,int> words;
  multimap <int,string> outs_words;
  ifstream read_file;
  string word;

  cout << "Input - text.txt, output - console."<< endl << endl;

  
  read_file.open("text.txt");               //из файла в map "words" с подсчётом встречаемости
  while (read_file>>word)
  {
    words[word]++;
  }
  read_file.close();
  
  
  map <string,int>::iterator cur;           //переливаем в мултимап "outs_words" наоборот,
  for (cur=words.begin();cur!=words.end();cur++)//теперь индекс - частота встречаемости
  {
    outs_words.insert(map<int,string>::value_type((*cur).second,(*cur).first));
  }


  multimap <int,string>::iterator cur_2;     //выводим всё это безобразие на консольку
  for (cur_2=--outs_words.end();cur_2!=--outs_words.begin();cur_2--)
  {
    cout<<(*cur_2).first<<" ";
    cout<<(*cur_2).second<<endl;
  }

  return 0;
}
