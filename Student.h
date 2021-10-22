struct student{
std::string imie;
std::string nazwisko;
std::string semestr;
std::string indeks;
//konstruktor

student(std::string s_imie, std::string s_nazwisko, std::string s_semestr, std::string s_indeks){
imie=s_imie;
nazwisko=s_nazwisko;
semestr=s_semestr;
indeks=s_indeks;
}


auto to_string() const -> std::string; 

};
