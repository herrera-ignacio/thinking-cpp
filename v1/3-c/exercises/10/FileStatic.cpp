// Static -> File scope means only available in this file
/*static */ int fs; 

// if using *static* linking this file with FileStatic2.cpp
// will cause a linker error

int main() {
  fs = 1;
}