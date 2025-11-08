# Base85 (Ascii85) Encoding

Base85 encoding provides better compression than Base64 by using 85 ASCII printable characters, commonly used in Adobe and PostScript.

## Usage

```cpp
#include "base85.h"
#include <iostream>

int main(){
    std::string text = "Hello";
    
    std::string encoded = base85_encode(text);
    std::cout << "Encoded: " << encoded << std::endl;
    // Output: <~87cURD]i~>
    
    std::string decoded = base85_decode(encoded);
    std::cout << "Decoded: " << decoded << std::endl;
    // Output: Hello
    
    return 0;
}
```

## Features
- Uses 85 ASCII printable characters
- Wrapped with `<~` and `~>` delimiters
- 4-byte groups encoded to 5 characters
- Special 'z' shorthand for all-zero groups
- More efficient than Base64 (~25% smaller)
- Common in Adobe PDF and PostScript
