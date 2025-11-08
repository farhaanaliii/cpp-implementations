# Base58 Encoding

Base58 encoding excludes visually similar characters (0, O, I, l) to avoid confusion, commonly used in Bitcoin addresses.

## Usage

```cpp
#include "base58.h"
#include <iostream>

int main(){
    std::string text = "Hello";
    
    std::string encoded = base58_encode(text);
    std::cout << "Encoded: " << encoded << std::endl;
    // Output: 9Ajdvzr
    
    std::string decoded = base58_decode(encoded);
    std::cout << "Decoded: " << decoded << std::endl;
    // Output: Hello
    
    return 0;
}
```

## Features
- Uses 1-9, A-Z, a-z (excluding 0, O, I, l)
- 58 characters total
- Avoids lookalike characters
- Big integer arithmetic for encoding
- Common in Bitcoin and cryptocurrency addresses
- Leading zeros preserved as '1' characters
