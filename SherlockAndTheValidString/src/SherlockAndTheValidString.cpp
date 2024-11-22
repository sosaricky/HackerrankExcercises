// Level : Medium
// Author : RaulSosa
// Status : Solved
#include<iostream>
#include<vector>
#include<cstdlib>
using namespace std;

struct repeat{
	char letter;
	int repeats;
};

//Pre: String tipo c++ @s
//Post: Devuelve un vector con las distinas letras usadas en  @s.
vector<char> GetLettersUsed(string s);


//Pre: String tipo c++ @s y un indice valido de @s
//Post: Devuelve true si encuentra el caracter @c a la izquierda de su posicion actual.
bool SearchLeft(string s, int i,char c);

//Pre: vector tipo vector<t> c++
//Post: Muestra el contenido de un vector de char.
void ShowCharVector(vector<char> v);

//Pre: string tipo c++ @s, char @c
//Post: Cant de coincidencias de @c en @s.
int CountCoincidences(string s,char c);

//Pre: string tipo c++ @s, numero de repeticiones  @n >=0
//Post: Devuelve un vector con los indices de aquellos caracteres que no están repetidos n veces en @s
vector<repeat> GetRepeatsOfLetters(string s);

//Pre: vector tipo c++ de char @v, @c caracter a buscar.
//Post: Devuelve -1 si no lo encuentra, el indice de su aparicion en caso contrario.
int SearchCharacter(vector<char> v,char c);

void ShowRepeatsOfLetters(vector<repeat> repeats);

string IsValid(string s);

//Pre: Vector tipo c++ @v
//Post: Devuelve las veces que mas se repiten los caracteres de una cadena
int GetMaxRepeat(vector<int> v);

int main(void){

	string s = "ihgchhiiheffiifeegcfdgbdeffhgeghdfhbfbifgidcafbfcd";

    cout << IsValid(s);
	return 0;
}


int GetMaxRepeat(vector<repeat> v){

    int maxCount = 0;
    int count = 0;
    int element = v[0].repeats;

    for(unsigned int i = 0;i<v.size()-1;i++){
        while(v[i].repeats == v[i+1].repeats){
            count++;
            i++;
        }
        if(count > maxCount){
            maxCount = count;
            element = v[i].repeats;
        }
        count = 0;
    }
    return element;

}


string IsValid(string s){

	vector<repeat> repeats = GetRepeatsOfLetters(s);
	int maxRepeat = GetMaxRepeat(repeats);
	int fixeables = 0,nonFixeables = 0;
    string result;

    for(unsigned int j = 0;j<repeats.size();j++){
        if(abs(maxRepeat - repeats[j].repeats) == 1  || repeats[j].repeats == 1){
            fixeables++;
        }else if(abs(maxRepeat - repeats[j].repeats) > 1 ){
            nonFixeables++;
        }
    }
    fixeables > 1 || nonFixeables > 0 ? result = "NO" : result = "YES";
	return result;
}

vector<char> GetLettersUsed(string s){

	vector<char> letters;

	for(unsigned int i=0;i<s.length();i++){
		if(!SearchLeft(s,i,s[i])){
			letters.push_back(s[i]);
		}
	}
	return letters;
}

void ShowCharVector(vector<char> v){

	for(unsigned int i=0;i<v.size();i++){
		cout << v[i] << " " ;
	}

}
bool SearchLeft(string s,int i,char c){

	int j = 0;

	while(j<i && c != s[j]){
		j++;
	}
	return j == i ? false : true;
}
int CountCoincidences(string s,char c){

	int count = 0;

	for(long unsigned int i=0;i<s.length();i++){
		s[i] == c ? count++ : count;
	}
	return count;
}
vector<repeat> GetRepeatsOfLetters(string s){

	vector<char> letters = GetLettersUsed(s);
	vector<repeat> repeatsOfLetters;
	repeat currentRepeat;

	//Obtengo cuantas veces está repetida cada letra y genero un vector con ellas.
	for(long unsigned int i=0;i<letters.size();i++){
		currentRepeat.letter = letters[i];
		currentRepeat.repeats = CountCoincidences(s,letters[i]);
		repeatsOfLetters.push_back(currentRepeat);
	}
	return repeatsOfLetters;
}
int SearchCharacter(vector<char> v,int c){

	long unsigned int i = 0;

	while(i < v.size() && c != v[i]){
		i++;
	}
	return i == v.size() ? -1 : i;
}
void ShowRepeatsOfLetters(vector<repeat> repeats){

	for(unsigned int i=0;i<repeats.size();i++){
		cout << repeats[i].letter << " => " << repeats[i].repeats << endl;
	}
}
