#include <iostream>
using namespace std;
int limit = 50000000;

void perfekt() {
  for(int i = 1; i < limit; i++) {
    int divisorSum = 0;
    for(int j = 1; j <= i/2; j++) {
      if( i % j == 0) {
        divisorSum +=j;
      }
    }
    if(divisorSum == i) {
      cout << i << endl;
    }
  }

}

int main() {
  perfekt();
  return 0;
}
