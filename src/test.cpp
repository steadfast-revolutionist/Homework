#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char** argv)
{
  string indata;
  string outdata;

  cout << "please enter a sentence: ";
  getline(cin, indata);
  getchar();

  ofstream outfile;
  outfile.open("report4/fio.txt");
  outfile << indata << endl;
  outfile.close();

  ifstream infile;
  infile.open("report4/fio.txt");
  cout << "you entered: ";
  infile >> outdata;
  cout << outdata << '\n';
  infile.close();

  return 0;
}
