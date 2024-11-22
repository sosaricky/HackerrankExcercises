// Level :  Easy
// Author : RaulSosa
// Status : Solved
#include<iostream>
#include<vector>
using namespace std;

//Pre: vector<char> y caracter.
//Post: Devuelve true si encontro el caracter en la cadena
bool SearchCharacterInVector(vector<char> s,char c);

//Pre: String tipo c++
//Post : Determina si un string es divisible en mitades.
bool IsDivisibleString(string s);

//Pre: String valido (no array de char por ejemplo) y divisible en mitades.
//Post: Devuelve vector con las mitades del string recibido.
vector<string> SplitInHalf(string s);

//Pre: Debe recibir 2 strings de igual longitud.
//Post: Devuelve los cambios minimos para que un string sea anagrama del otro.
int GetMinimunChangesToBeAnagram(string s1,string s2);

//Pre : string s,comienzo y fin del substring a obtener deben ser indices validos en s
//Post : Substring buscado segun begin y end.
string GetSubString(string s,int begin,int end);

//Pre: String tipo c++
//Post: Devuelve la minima cantidad de caract a cambiar para obtener un anagrama en sus mitades..
int Anagram(string s);

//Pre: String tipo c++  y caracter
//Post: Devuelve la cantidad de aparciones del caracter @c en  @s
int CountCoincidences(string s,char c);

int main(void){
	
	string test1 = "fdhvsolfpafhalll";
	cout << Anagram("xaxbbbxx");

	return 0;
}

int Anagram(string s){
	if(IsDivisibleString(s)){
		// SplitInHalf(s)[0] - Primera mitad , SplitInHalf(s)[1] - Segunda mitad.
		return GetMinimunChangesToBeAnagram(SplitInHalf(s)[0],SplitInHalf(s)[1]);
	}else{
		return -1;
	}
}

bool IsDivisibleString(string s){
	return s.length()%2 ? false : true;
}

vector<string> SplitInHalf(string s){

	vector<string> halfs;

	halfs.push_back(GetSubString(s,0,(s.length()-1)/2));
	halfs.push_back(GetSubString(s,s.length()/2,s.length()-1));

	return halfs;

}

int GetMinimunChangesToBeAnagram(string s1,string s2){

	int changes = 0;
	// Array para guardar todas las letras distintas que aparecen
	vector<char> letters;
	// Obtengo las todas letras distintas que se incluyen en s1 y s2 y las guardo en letters.
	for(unsigned int i=0;i<s1.length();i++){
		if(!SearchCharacterInVector(letters,s1[i])){
			letters.push_back(s1[i]);
		}
		if(!SearchCharacterInVector(letters,s2[i])){
			letters.push_back(s2[i]);
		}
	}
	// Cuento las veces que aparece cada letra de s1 y s2 en letters.
	for(unsigned int i=0;i<letters.size();i++){
		int matchesS1 = CountCoincidences(s1,letters[i]);
		int matchesS2 = CountCoincidences(s2,letters[i]);
		// Para una letra dada comparo las coincidencias en s1 y s2.
		// La diferencia entre ellas me da la cantidad de cambios para que su cantidad la misma en ambos strings
		matchesS1 > matchesS2 ? changes += matchesS1-matchesS2 : changes;
	}
	return changes;
}

string GetSubString(string s,int begin,int end){

    int j,i = begin,lengthSubString = end-begin+1;
    char subString[lengthSubString+1];

    for(j=0;j<lengthSubString && i<=end ;j++){
        subString[j] = s[i];
        i++;
    }
    subString[j] = '\0';
    string result = subString;

    return result;
}

bool SearchCharacterInVector(vector<char> s,char c){
	unsigned int i = 0;
	while(i<s.size() && s[i] != c){
		i++;
	}
	return i == s.size() ? false : true;
}

int CountCoincidences(string s, char c){
	int count = 0;
	for(unsigned int i=0;i<s.size();i++){
		if(c == s[i]){
			count++;
		}
	}
	return count;
}
