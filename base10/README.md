# Base10 (Decimal) Encoding

Decimal encoding represents each byte as a space-separated decimal number.

## Usage

```cpp
#include "base10.h"
#include <iostream>

int main(){
    std::string text = "Hi";
    
    std::string encoded = base10_encode(text);
    std::cout << "Encoded: " << encoded << std::endl;
    // Output: 72 105
    
    std::string decoded = base10_decode(encoded);
    std::cout << "Decoded: " << decoded << std::endl;
    // Output: Hi
    
    return 0;
}
```

## Features
- Human-readable decimal format
- Space-separated byte values
- Simple and intuitive
- Uses standard streams for parsing
