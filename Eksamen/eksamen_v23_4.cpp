//
// Created by amund on 04.12.2024.
//
//a

char forsteSingleBokstav(const char tekst[], const int n){
  int i, j;                      //  Løkkevariable.
  bool duplikat;                                 //  Verdien/elementet som evt.
  for(int i = 0; i<= n; i++){
   duplikat == false;
   for(int j = 0; i <=n; j++){
   if( i!=j && tekst[i] == tekst[j]){
    duplikat == true;
    break;
   }
   if(!duplikat) return tekst[i];
    }
   return *" ";
    }

}
char forsteSingleBokstav2(const char tekst[], const int n){
 char hjelpetekst[100];
 int len = 0;
 for(int i = 0; i<n; i++){
  char bokstav = tekst[i];
  for(int j = 0; j<len; j++){
  if(tekst[i] != hjelpetekst[j]) {
   hjelpetekst[j] = tekst[i];
  }


 }
 
}
