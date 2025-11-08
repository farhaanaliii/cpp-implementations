# Base2 (Binary) Encoding

Binary encoding converts text to its raw binary representation using 0s and 1s.

## Usage

```cpp
#include "base2.h"
#include <iostream>

int main(){
    std::string text = "Hi";
    
    std::string encoded = base2_encode(text);
    std::cout << "Encoded: " << encoded << std::endl;
    // Output: 0100100001101001
    
    std::string decoded = base2_decode(encoded);
    std::cout << "Decoded: " << decoded << std::endl;
    // Output: Hi
    
    return 0;
}
```

## Features
- Simple binary representation
- 8 bits per character
- No padding required
