#include <string>
#include <bitset>
#include <stdexcept>

char BASE32_CHARS[32] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '2', '3', '4', '5', '6', '7'};

int is_base32(char c){
    for(int i=0; i<32; i++){
        if(c == BASE32_CHARS[i]){
            return i;
        }
    }

    return -1;
}

// direction: 1 => left
// direction: 0 => right
std::string str_pad(std::string &str, int pad_len, char pad_char, int direction){
	if(str.length() >= pad_len){
		return str;
	}
	
	std::string _str = str;
	
	for(int i=0; i<pad_len - str.length(); i++){
		if(direction == 1){
			_str = pad_char + _str;
		}else{
			_str = _str + pad_char;
		}
	}
	
	return _str;
}


std::string base32_encode(std::string text){
	std::string bin_str = "";
	
	for(int i=0; i<text.length(); i++){
        std::string bits = std::bitset<8>((int)text[i]).to_string();
		bin_str += bits;
	}
	
    std::string base32_str = "";
    for(int i=0; i<bin_str.length(); i+=5){
        std::string s5 = bin_str.substr(i, 5);
        s5 = str_pad(s5, 5, '0', 0);
        base32_str += BASE32_CHARS[stoi(s5, nullptr, 2)];
    }

    if(base32_str.length() % 8 != 0){
        int gap = 8 - (base32_str.length() % 8);
        base32_str = str_pad(base32_str, base32_str.length() + gap, '=', 0);
    }

	return base32_str;
}

std::string base32_decode(std::string encoded){
    std::string bits_str = "";
    for(int i=0; i<encoded.length(); i++){
        if(encoded[i] == '=') continue;

        int index = is_base32(encoded[i]);
        if(index == -1){
            throw std::runtime_error("Invalid base32 char");
        }

        std::string bits = std::bitset<5>(index).to_string();
        bits_str += bits;
    }

    std::string decoded_str = "";
    for(int i=0; i<bits_str.length(); i+=8){
        std::string s8 = bits_str.substr(i, 8);
        if(s8.length() != 8) break;
        decoded_str += (char)stoi(s8, nullptr, 2);
    }

    return decoded_str;
}
