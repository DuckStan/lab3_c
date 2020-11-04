
#include <iostream>
#include "Hex.h"
#include "pch.h"
#include "Hex.h"
#include "math.h"
#include <string.h>

namespace lab3 {
	Hex::Hex() : hex(new char[3]), form_sm(new char[6]), form_1(new char[6]), form_2(new char[6]) {
		len = 1;
	
		hex[0] = '+';
		hex[len] = '0';
		for(int i=0;i<len*4; i++){
			form_sm[i] = '0';
			form_1[i] = '0';
			form_2[i] = '0';
		}
		hex[len+1] = '\0';
		form_sm[len*4+1] = '\0';
		form_1[len*4+1] = '\0';
		form_2[len*4+1] = '\0';
	}
	char int_to_hex(int value) {
		switch(value){
		case 0:
			return '0';
		case 1:
			return '1';
		case 2:
			return '2';
		case 3:
			return '3';
		case 4:
			return '4';
		case 5:
			return '5';
		case 6:
			return '6';
		case 7:
			return '7';
		case 8:
			return '8';
		case 9:
			return '9';
		case 10:
			return 'A';
		case 11:
			return 'B';
		case 12:
			return 'C';
		case 13:
			return 'D';
		case 14:
			return 'E';
		case 15:
			return 'F';
		}
	}
	int hex_to_binary(char hex_value) {
		switch (hex_value) {
		case '0':
			return 0;
		case '1':
			return 4;
		case '2':
			return 8;
		case '3':
			return 12;
		case '4':
			return 16;
		case '5':
			return 20;
		case '6':
			return 24;
		case '7':
			return 28;
		case '8':
			return 32;
		case '9':
			return 36;
		case 'A':
			return 40;
		case 'B':
			return 44;
		case 'C':
			return 48;
		case 'D':
			return 52;
		case 'E':
			return 56;
		case 'F':
			return 60;
		}
	}
	
	int Hex::set_forms() {
		const char holder[] = "0000000100100011010001010110011110001001101010111100110111101111";
		
		
		if (form_sm == nullptr)
			form_sm = new char[len * 4 + 2];
		else {
			char* tmp = form_sm;
			form_sm = new char[len * 4 + 2];
			for (int i = 0; i < strlen(tmp); i++)
				form_sm[i] = tmp[i];
			delete[] tmp;
		}
			

		if (form_1 == nullptr)
			form_1 = new char[len * 4 + 2];
		else {
			char* tmp = form_1;
			form_1 = new char[len * 4 + 2];
			for (int i = 0; i < strlen(tmp); i++)
				form_1[i] = tmp[i];
			delete[] tmp;
		}

		if (form_2 == nullptr)
			form_2 = new char[len * 4 + 2];
		else {
			char* tmp = form_2;
			form_2 = new char[len * 4 + 2];
			for (int i = 0; i < strlen(tmp); i++)
				form_2[i] = tmp[i];
			delete[] tmp;
		}

		if (hex[0] == '+') form_sm[0] = '0'; else form_sm[0] = '1';
		int s = 0, k=1; 

		for (int i = 1; i <= len; i++) {
			s = hex_to_binary(hex[i]);
			for (int j = 0; j < 4; j++) {
				form_sm[k + j] = holder[s + j];
			}
			k += 4;
		}
		form_sm[len*4+1]='\0';
		form_1[0] = form_sm[0];
		form_2[0] = form_sm[0]; 
		for (int i = 1; i <= len * 4; i++) {
			if (form_sm[i] == '0') {
				if (form_sm[0] == '0') {
					form_1[i] = '0';
					form_2[i] = '0';
				}
				else {
					form_1[i] = '1';
					form_2[i] = '1';
				}
			}
			else {
				if (form_sm[0] == '0') {
					form_1[i] = '1';
					form_2[i] = '1';
				}
				else {
					form_1[i] = '0';
					form_2[i] = '0';
				}
			}
		}
		form_1[len * 4 + 1] = '\0';
		form_2[len * 4 + 1] = '\0';
		int i = 0;
		i = len * 4;
		if (form_sm[0] == '0') return 0;
		while (i>0) {
			if (form_1[i] == '1') {
				form_2[i] = '0';
				i--;
				continue;
			}
			if (form_1[i] == '0') {
				form_2[i] = '1';
				break;
			}
		}
		return 0;
	}
	Hex::Hex(int hex_value) {
		 int tmp = hex_value;
		 int remainder=0;
		 char *fake_hex;
		if ((hex_value > 2147483647) || (hex_value < -2147483647))
			throw std::exception("Too big of a number!");
		len = 0;
		fake_hex = new char[1];
		if (hex_value >= 0) {
			*fake_hex = '+';
		}
		else *fake_hex = '-';

		int j = 1;
		tmp = fabs(tmp);

		while(1) {
			len++;
			char* tmp_1 = fake_hex;
			fake_hex = new char[len+2];
			for (int i = 0; i < strlen(tmp_1); i++)
				fake_hex[i] = tmp_1[i];
			delete[] tmp_1;
			remainder = tmp % 16;
			fake_hex[j] = int_to_hex(remainder);
			tmp = tmp / 16;
			if (tmp == 0) break;
			j++;
			
		}	
		if (tmp > 0) {
			throw std::exception("Invalid hex number!");
			delete[] fake_hex;
		} else {
			/*for (int i = 0; i < len; i++) {
				hex[i+1] = fake_hex[len - i];
			} */
			fake_hex[len+1] = '\0';
			hex = fake_hex;
			set_forms();
		}
	}
	int Hex::set_hex(char* hex_value) {
		int elements = 0;
		char holder[] = "+-0123456789ABCDEF";
		char* ptr = holder;
		int condition = 0;
		for (int i = 0; *(hex_value+i) != '\0'; i++) {
			condition = 0;
			for (int j = 0; j < strlen(holder); j++) {
				if (holder[j] == *(hex_value+i)) {
					condition = 1;
					break;
				}
			}
			if (condition == 0)
				throw std::exception("Invalid characters!");
			elements++;
		}
		condition = 0;
		if (hex == nullptr)
			hex = new char[1];
		if (*(hex_value) == '-') {
			hex[0] = '-';
			elements--;
			condition = 1;
		}
		else {
			if (*(hex_value) == '+') {
				hex[0] = '+';
				elements--;
				condition = 1;
			}
			else {
				hex[0] = '+';
			}
		}

		if (elements == 0) {
			throw std::exception("Innaceptable length!");
		}

		len = elements;
		char* tmp_1 = hex;
		hex = new char[len + 2];
		for (int i = 0; i < strlen(tmp_1); i++)
			hex[i] = tmp_1[i];
		delete[] tmp_1;

		for (int i = 0; i < len; i++) {
			if (condition) {
				hex[i+1] = *(hex_value + i+1);
				continue;
			}
			hex[i+1] = *(hex_value+i);
		}
		hex[len+1] = '\0';
		return 0;
	}
	Hex::Hex(char *hex_value) {
		try {
			set_hex(hex_value);
		}
		catch (std::exception &ex) {
			throw std::exception(ex.what());
		}
		set_forms();
	}
	Hex::Hex(const Hex& a):len(a.len) {
		//std::cout << len << std::endl;
		hex = new char[len+2];
		form_sm = new char[len*4+2];
		form_1 = new char[len * 4 + 2];
		form_2 = new char[len * 4 + 2];
		//std::cout << a.hex << std::endl;
		for (int i = 0; i < len * 4 + 1; i++) {
			if (i <= len + 1)
				hex[i] = a.hex[i];
			//std::cout << hex[i] << std::endl;
			form_sm[i] = a.form_sm[i];
			form_1[i] = a.form_1[i];
			form_2[i] = a.form_2[i];
		}
		//std::cout << hex << std::endl;
	}
	Hex::Hex(Hex&& a) noexcept: len(a.len), hex(a.hex), form_sm(a.form_sm), form_1(a.form_1), form_2(a.form_2) {
		a.hex = nullptr;
		a.form_sm = nullptr;
		a.form_1 = nullptr;
		a.form_2 = nullptr;
	}
	Hex& Hex::operator =(const Hex& b) { //copy
		if (this != &b) {
			len = b.len;
			if( hex !=nullptr)
				delete[] hex;
			if(form_sm!=nullptr)
				delete[] form_sm;
			if(form_1 !=nullptr)
				delete[] form_1;
			if(form_2!=nullptr)
				delete[] form_2;
			hex = new char[len + 2];
			form_sm = new char[len * 4 + 2];
			form_1 = new char[len * 4 + 2];
			form_2 = new char[len * 4 + 2];
			for (int i = 0; i < len * 4 + 1; i++) {
				if (i <= len + 1)
					hex[i] = b.hex[i];
				form_sm[i] = b.form_sm[i];
				form_1[i] = b.form_1[i];
				form_2[i] = b.form_2[i];
			}
		}
		return *this;
	}
	Hex& Hex::operator =(Hex&& a) noexcept { //displace
		int tmp = len;
		len = a.len;
		a.len = len;
		char* ptr = a.hex;
		hex = a.hex;
		a.hex = ptr;
		ptr = a.form_sm;
		form_sm = a.form_sm;
		ptr = a.form_1;
		form_1 = a.form_1;
		ptr = a.form_2;
		form_2 = a.form_2;
		return *this;
	}
	Hex& Hex::input(std::istream& s) {
		char input_s[80];
		std::cout << "Input the hex number:" << std::endl;
		s >> input_s;
		if (!std::cin.good())
			throw std::exception("Invalid length of hex number!");
		try {
			set_hex(input_s);
		}
		catch (std::exception& ex) {
			std::cout << ex.what() << std::endl;
		} 
		set_forms();
		return *this;
	}

	Hex& Hex::shift_left(int n) {
		for (int i = 1; i <= len; i++) {
			if (i + n > len) {
				hex[i] = '0';
				continue;
			}
			hex[i] = hex[i + n];
		}
		set_forms();
		return *this;
	}

	Hex& Hex::shift_right(int n, int condition) {
		if (condition == 1) {
			len += n + 1;
			char* tmp_1 = hex;
			hex = new char[len];
			for (int i = 0; i < strlen(tmp_1); i++)
				hex[i] = tmp_1[i];
			delete[] tmp_1;
		}
		for (int i = len; i >= 1; i--) {
			if (i - n < 1) {
				hex[i] = '0';
				continue;
			}
			hex[i] = hex[i - n];
		}
		if (condition == 1) {
			len--;
			char* tmp_1 = hex;
			hex = new char[len+2];
			for (int i = 0; i < strlen(tmp_1); i++)
				hex[i] = tmp_1[i];
			delete[] tmp_1;
		}
		set_forms();
		return *this;
		
	}
	
	std::ostream& Hex::print(std::ostream& s) const {
		s << hex;
		s << std::endl;
		return s;
	}
	char binary_to_hex(int binary_value) {
		switch (binary_value) {
		case 0:
			return '0';
		case 4:
			return '1';
		case 8:
			return '2';
		case 12:
			return '3';
		case 16:
			return '4';
		case 20:
			return '5';
		case 24:
			return '6';
		case 28:
			return '7';
		case 32:
			return '8';
		case 36:
			return '9';
		case 40:
			return 'A';
		case 44:
			return 'B';
		case 48:
			return 'C';
		case 52:
			return 'D';
		case 56:
			return 'E';
		case 60:
			return 'F';
		}
	}
	int Hex::set_forms_backwards() {
		const char holder[] = "0000000100100011010001010110011110001001101010111100110111101111";
		
		

		for (int i = 0; i < len*4+1; i++) {
			form_1[i] = form_2[i];
			form_sm[i] = form_2[i];
		}

		int i = 0;
		i = len * 4;
		if (form_2[0] == '1') {
			while (i > 0) {
				if (form_1[i] == '0') {
					form_2[i] = '1';
					i--;
					continue;
				}
				if (form_1[i] == '1') {
					form_2[i] = '0';
					break;
				}
			}
		}
		if (form_2[0] == '1') {
			for (int i = 1; i <= len * 4; i++) {
				if (form_1[i] == '0') {
					form_sm[i] = '1';
				}
				else {
					form_sm[i] = '0';
				}

			}
		}
		else {
			for (int i = 0; i < len * 4; i++) {
				form_sm[i] = form_2[i];
			}
		}
		form_sm[len * 4 + 1] = '\0';

		if (form_sm[0] == '0') hex[0] = '+'; else hex[0] = '-';
		
		int s = 0, k = 1, c = 0;
		for (int i = 1; i <= len*4; i+=4) {
			while (s <= 60) {
				for (int j = 0; j < 4; j++) {
					if(form_sm[i + j] == holder[s + j]) c++;
				}
				if (c == 4) {
					hex[k] = binary_to_hex(s);
					k++;
					c = 0;
					break;
				}
				else c = 0;
				s += 4;
			}
			s = 0;
		}
		hex[len + 1] = '\0';
		return 0;
	}
	
	Hex& Hex::add(Hex b) const{
		Hex tmp = *this;
		int i = 0;
		Hex c;
		Hex* ptr = &c;

		if (tmp.len > b.len) {
			b = b.shift_right(tmp.len - b.len, 1);
			i = tmp.len * 4+1;
			c = tmp;
		}
		if (tmp.len < b.len) {
			tmp=tmp.shift_right(b.len - tmp.len, 1);
			i = b.len * 4+1;
			c = b;
		}
		if (tmp.len == b.len) { 
			i = tmp.len * 4+1;
			c = tmp;
		}
		std::cout << c.hex << std::endl;
		int v_ume = 0;
		while (i >= 0) {
			if ((tmp.form_2[i] == '1') && (b.form_2[i] == '1') && (v_ume == 1)) {
				c.form_2[i] = '1';
				v_ume = 1;
				i--;
				continue;
			}
			if ((((tmp.form_2[i] == '0') && (b.form_2[i] == '1')) || ((tmp.form_2[i] == '1') && (b.form_2[i] == '0'))) && (v_ume == 1)) {
				c.form_2[i] = '0';
				v_ume = 1;
				i--;
				continue;
			}
			if ((tmp.form_2[i] == '0') && (b.form_2[i] == '0') && (v_ume == 1)) {
				c.form_2[i] = '1';
				v_ume = 0;
				i--;
				continue;
			}
			if ((tmp.form_2[i] == '1') && (b.form_2[i] == '1')) {
				c.form_2[i] = '0';
				v_ume = 1;
				i--;
				continue;
			}
			if ((tmp.form_2[i] == '0') && (b.form_2[i] == '0')) {
				c.form_2[i] = '0';
				i--;
				continue;
			}
			if ((((tmp.form_2[i] == '0') && (b.form_2[i] == '1')) || ((tmp.form_2[i] == '1') && (b.form_2[i] == '0')))) {
				c.form_2[i] = '1';
				i--;
				continue;
			}
			c.form_2[i] = '\0';
			i--;
		}
		if ((tmp.form_2[0] == '0') && (b.form_2[0] == '0') && (c.form_2[0] == '1'))
			throw std::exception("Overload detected!");
		if ((tmp.form_2[0] == '1') && (b.form_2[0] == '1') && (c.form_2[0] == '0'))
			throw std::exception("Overload detected!");
		std::cout << c.form_2 << std::endl;
		c.set_forms_backwards();
		std::cout << c.hex << std::endl;
		return ptr;
	}
	Hex& Hex::subtract(Hex b) const {
		Hex c;
		if (b.hex[0] == '-') b.hex[0] = '+'; else b.hex[0] = '-';;
		b.set_forms();
		try {
			c = this->add(b);
		}
		catch (std::exception &ex) {
			throw std::exception(ex.what());
		}
		return c;
	}
	int hex_to_int(char value) {
		switch (value) {
		case '0':
			return 0;
		case '1':
			return 1;
		case '2':
			return 2;
		case '3':
			return 3;
		case '4':
			return 4;
		case '5':
			return 5;
		case '6':
			return 6;
		case '7':
			return 7;
		case '8':
			return 8;
		case '9':
			return 9;
		case 'A':
			return 10;
		case 'B':
			return 11;
		case 'C':
			return 12;
		case 'D':
			return 13;
		case 'E':
			return 14;
		case 'F':
			return 15;
		}
	}
	int Hex::comp(Hex b) const {
		int sum_1 = 0, sum_2 = 0;
		Hex tmp(*this);
		for (int i = 1; i <= tmp.len; i++) {
			sum_1 += hex_to_int(tmp.hex[i]) * pow(16, tmp.len - i);
		}
		for (int i = 1; i <= b.len; i++) {
			sum_2 += hex_to_int(b.hex[i]) * pow(16, tmp.len - i);
		}
		if (sum_1 > sum_2) return 1;
		if (sum_1 < sum_2) return 2;
		if (sum_1 == sum_2) return 3;
	}
	int Hex::is_even() const{
		if ((this->hex[len] == '0') || (this->hex[len] == '2') || (this->hex[len] == '4') || (this->hex[len] == '6') || (this->hex[len] == '8') || (this->hex[len] == 'A') || (this->hex[len] == 'C') || (this->hex[len] == 'E'))
			return 1;
		else return 2;
	}
	void Hex::getHex(char *outstr) const {
		for (int i = 0; i < len + 1; i++) {
			*(outstr+i) = hex[i];
		}
	}
	void Hex::get_form_sm(char* outstr) const {
		for (int i = 0; i < len*4 + 1; i++) {
			*(outstr + i) = form_sm[i];
		}
	}
	void Hex::get_form_1(char* outstr) const {
		for (int i = 0; i < len*4 + 1; i++) {
			*(outstr + i) = form_1[i];
		}
	}
	void Hex::get_form_2(char* outstr) const {
		for (int i = 0; i < len*4 + 1; i++) {
			*(outstr + i) = form_2[i];
		}
	}
	std::istream& operator >>(std::istream& s, Hex& a) {
		a.input(s);
		return s;
	}
	std::ostream& operator <<(std::ostream& s, Hex& a) {
		a.print(s);
		return s;
	}
	Hex& Hex::operator <<= (int n) {
		shift_left(n);
		return *this;
	}
	Hex& Hex::operator >>= (int n) {
		shift_right(n);
		return *this;
	}
	Hex& Hex::operator +(Hex b) const {
		Hex c;
		c = this->add(b);
		return c;
	}
	Hex& Hex::operator -(Hex b) const {
		Hex c;
		c = this->subtract(b);
		return c;
	}



}