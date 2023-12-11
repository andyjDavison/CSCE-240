// Copyright 2022 CSCE240 hipp
#include<probability.h>
using csce240_program5::Probability;
#include<iostream>
using std::cout;
using std::endl;

int main() {
  const Probability half(1, 2);
  const Probability twothirds(2, 3);

  if ( half.ToString() == "1/2" )
    cout << "passed first ToString test" << endl;
  else
    cout << "failed first ToString test" << endl;

  if ( twothirds.ToString() == "2/3" )
    cout << "passed second ToString test" << endl;
  else
    cout << "failed second ToString test" << endl;

  return 0;
}
