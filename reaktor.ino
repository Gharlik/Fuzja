#include <LiquidCrystal_I2C.h>
#include <Wire.h>
LiquidCrystal_I2C lcd(0x27, 20, 4);
bool pokaz_menu = true;
bool pozwolenie_na_kont = false;
void ekran(String tekst){
   lcd.clear();           //maksymalna długośc tekstu 20 znaków
   lcd.setCursor(0,0);
   lcd.print(tekst);
   lcd.setCursor(0, 3);
   lcd.print("stop");
}

void ekran_pusty(String tekst){
  lcd.clear();           //maksymalna długośc tekstu 20 znaków
   lcd.setCursor(0,0);
   lcd.print(tekst);
}

void ekran_czujniki(){
     lcd.clear();           //maksymalna długośc tekstu 15 znaków
   lcd.setCursor(0,3);
   lcd.print("ESC");
   lcd.setCursor(0, 0);
   lcd.print("cisnienie");
   lcd.setCursor(0, 1);
   lcd.print("paliwo min");
   lcd.setCursor(0, 2);
   lcd.print("paliwo max");
  while(digitalRead(A3)==LOW){
    lcd.setCursor(18,0);
    if(digitalRead(5)==HIGH){
      lcd.print("ON");
    }
    else{
      lcd.print("OF");
    }
    lcd.setCursor(18,1);
    if(digitalRead(6)==HIGH){
      lcd.print("ON");
    }
    else{
      lcd.print("OF");
    }
    lcd.setCursor(18,2);
    if(digitalRead(7)==HIGH){
      lcd.print("ON");
    }
    else{
      lcd.print("OF");
    }
    delay(100);
  }
}

void ekran_cyfra(int cyfra){
   lcd.clear();           //maksymalna długośc tekstu 20 znaków
   lcd.setCursor(0,0);
   lcd.print(cyfra);
   lcd.setCursor(0, 3);
   lcd.print("stop");
}

void ekran_fuzja(String tekst){
   lcd.clear();           //maksymalna długośc tekstu 20 znaków
   lcd.setCursor(0,0);
   lcd.print(tekst);
   lcd.setCursor(0, 3);
   lcd.print("stop");
   lcd.setCursor(15, 3);
   lcd.print("fuzja");
}

void ekran_menu(String tekst){
   lcd.clear();           //maksymalna długośc tekstu 20 znaków
   lcd.setCursor(0,0);
   lcd.print(tekst);
   lcd.setCursor(5, 3);
   lcd.print("kont");
   lcd.setCursor(10, 3);
   lcd.print("start");
   lcd.setCursor(16, 3);
   lcd.print("serw");
}

void ekran_stop(String tekst){
   lcd.clear();           //maksymalna długośc tekstu 20 znaków
   lcd.setCursor(0,0);
   lcd.print(tekst);
   lcd.setCursor(0, 3);
   lcd.print("atmo");
   lcd.setCursor(5, 3);
   lcd.print("menu");
}

void ekran_cyfra_i_tekst(String tekst, int cyfra){
  lcd.clear();           //maksymalna długośc tekstu 15 znaków
   lcd.setCursor(0,0);
   lcd.print(tekst);
   lcd.setCursor(17, 0);
   lcd.print(cyfra);
   lcd.setCursor(0, 3);
   lcd.print("stop");
}
void ekran_cykle(String tekst, int cyfra){
  lcd.clear();           //maksymalna długośc tekstu 15 znaków
   lcd.setCursor(0,0);
   lcd.print(tekst);
   lcd.setCursor(0, 1);
   lcd.print("cykl nr. ");
   lcd.print(cyfra);
   lcd.setCursor(0, 3);
   lcd.print("stop");
}
void ekran_serwis(String tekst_dolny,String tekst_srodkowy,String tekst_gorny, int przedmiot){
  lcd.clear();           //maksymalna długośc tekstu 15
   
  if(przedmiot == 12){                                                //przed fuzja
   if(digitalRead(przedmiot+1) == HIGH){
   lcd.setCursor(0,0);
   lcd.print(tekst_gorny);
   lcd.setCursor(16,0);
   lcd.print("X");
   }
   else if(digitalRead(przedmiot+1) == LOW){
   lcd.setCursor(0,0);
   lcd.print(tekst_gorny);
   }
   if(digitalRead(przedmiot) == LOW){
   lcd.setCursor(0,1);
   lcd.print(tekst_srodkowy);
   if(przedmiot != 7 ){
   lcd.setCursor(16,1);
   lcd.print("X");
   }
   lcd.setCursor(18,1);
   lcd.print("<--");
   }
   else if(digitalRead(przedmiot) == HIGH){
   lcd.setCursor(0,1);
   lcd.print(tekst_srodkowy);
   lcd.setCursor(18,1);
   lcd.print("<--");
   }
   if(digitalRead(przedmiot - 1) == LOW){
   lcd.setCursor(0,2);
   lcd.print(tekst_dolny);
   if(przedmiot != 8 ){
   lcd.setCursor(16,2);
   lcd.print("X");
   }
   }
   else if(digitalRead(przedmiot - 1) == HIGH){
   lcd.setCursor(0,2);
   lcd.print(tekst_dolny);
   }

  }                                                         //tuż przed fuzja
  else if(przedmiot == 13){                                 //podczas fuzji
     if(digitalRead(przedmiot - 1) == LOW){
   lcd.setCursor(0,2);
   lcd.print(tekst_dolny);
   lcd.setCursor(16,2);
   lcd.print("X");
   }
   else if(digitalRead(przedmiot - 1) == HIGH){
   lcd.setCursor(0,2);
   lcd.print(tekst_dolny);
   }

   if(digitalRead(przedmiot) == HIGH){
   lcd.setCursor(0,1);
   lcd.print(tekst_srodkowy);
   lcd.setCursor(16,1);
   lcd.print("X");
   lcd.setCursor(18,1);
   lcd.print("<--");
   }
   else if(digitalRead(przedmiot) == LOW){
   lcd.setCursor(0,1);
   lcd.print(tekst_srodkowy);
   lcd.setCursor(18,1);
   lcd.print("<--");
   }
   lcd.setCursor(0,0);
   lcd.print(tekst_gorny);
   }
  else if(przedmiot == 7){
   if(digitalRead(przedmiot+1) == LOW && digitalRead(przedmiot+1) != 7){
   lcd.setCursor(0,0);
   lcd.print(tekst_gorny);
   lcd.setCursor(16,0);
   lcd.print("X");
   }
   else if(digitalRead(przedmiot+1) == HIGH && digitalRead(przedmiot+1) != 7){
   lcd.setCursor(0,0);
   lcd.print(tekst_gorny);
   }
   if(digitalRead(przedmiot) == LOW){
   lcd.setCursor(0,1);
   lcd.print(tekst_srodkowy);
   lcd.setCursor(16,1);
   lcd.print("X");
   lcd.setCursor(18,1);
   lcd.print("<--");
   }
   else if(digitalRead(przedmiot) == HIGH){
   lcd.setCursor(0,1);
   lcd.print(tekst_srodkowy);
   lcd.setCursor(18,1);
   lcd.print("<--");
   }
  }
   else{                                                      //po fuzji
   if(digitalRead(przedmiot+1) == LOW && digitalRead(przedmiot+1) != 7){
   lcd.setCursor(0,0);
   lcd.print(tekst_gorny);
   lcd.setCursor(16,0);
   lcd.print("X");
   }
   else if(digitalRead(przedmiot+1) == HIGH && digitalRead(przedmiot+1) != 7){
   lcd.setCursor(0,0);
   lcd.print(tekst_gorny);
   }

   if(digitalRead(przedmiot) == LOW){
   lcd.setCursor(0,1);
   lcd.print(tekst_srodkowy);
   lcd.setCursor(16,1);
   lcd.print("X");
   lcd.setCursor(18,1);
   lcd.print("<--");
   }
   else if(digitalRead(przedmiot) == HIGH){
   lcd.setCursor(0,1);
   lcd.print(tekst_srodkowy);
   lcd.setCursor(18,1);
   lcd.print("<--");
   }

   if(digitalRead(przedmiot - 1) == LOW && digitalRead(przedmiot) != 14){
   lcd.setCursor(0,2);
   lcd.print(tekst_dolny);
   lcd.setCursor(16,2);
   lcd.print("X");
   }
   else if(digitalRead(przedmiot - 1) == HIGH && digitalRead(przedmiot) != 14){
   lcd.setCursor(0,2);
   lcd.print(tekst_dolny);
   }
   }

   lcd.setCursor(0, 3);
   lcd.print("wyjdz");
   lcd.setCursor(6, 3);
   lcd.print("gora");
   lcd.setCursor(12, 3);
   lcd.print("dol");
   lcd.setCursor(16, 3);
   lcd.print("test");
}

int Stop(){
  digitalWrite(8,HIGH);
  digitalWrite(9,HIGH);
  digitalWrite(10,HIGH);
  digitalWrite(11,HIGH);
  digitalWrite(12,HIGH);
  digitalWrite(13,LOW);
  ekran_stop("zatrzymanie awaryjne");
          delay(2000);
          ekran_stop("wybierz dalsza opcje");
            while(digitalRead(2)==LOW){
                if(digitalRead(A3) == HIGH){
                  digitalWrite(10, LOW);
                  ekran("zawor powietrza otw.");
                  delay(2000);
                  while(digitalRead(A3)==LOW){
                  delay(100);
                  }
                  digitalWrite(10,HIGH);
                  ekran("wyslanie do menu");
                return 1;
              }
            }
            return 1;
}

int Paliwo(int ile_razy,int x){
  do{
      ekran_cykle("napelnianie",x);
  do{                                             //napełnianie zbiornika
    delay(100);
      if(digitalRead(A3) == HIGH){
          if(Stop()==1)
          return 0;
        }
        if(digitalRead(6)==HIGH){
          delay(1000);
          if(digitalRead(6)==HIGH){
          break;
        }
        }
  }
  while(true);
  delay(100);
    if(digitalRead(A3) == HIGH){
         if(Stop()==1)
          return 0;
        }
  ekran_cykle("paliwo maksymalne",x);
  delay(1000);                                //pełny zbiornik
    if(digitalRead(A3) == HIGH){
          if(Stop()==1)
          return 0;
        }
  ekran_cykle("zawor paliwa otwarty",x);
  digitalWrite(11, LOW);
  do{
    delay(100);
      if(digitalRead(A3) == HIGH){
          if(Stop()==1)
          return 0;
        }
  }
  while(digitalRead(7)==HIGH);
  digitalWrite(11, HIGH); 
      if(digitalRead(A3) == HIGH){
          if(Stop()==1)
          return 0;
        }
  ekran_cykle("zawor paliwa zamk.",x);                           //pusty zbiornik
  delay(1000);
  ekran_cykle("paliwo min",x);
  delay(1000);
   ekran_cykle("pompa on",x);              //opróżnianie paliwa
  digitalWrite(8, LOW);
  delay(1000);
  
    if(digitalRead(A3) == HIGH){
          if(Stop()==1)
          return 0;
        }
  ekran_cykle("zawor pompy otwarty",x);         //poprawianie ciśnienia
  digitalWrite(12, LOW);
  delay(100);
  ekran_cykle("regulacja cisnienia",x);
  do{
    delay(100);
      if(digitalRead(A3) == HIGH){
          if(Stop()==1)
          return 0;
        }
  }
  while(digitalRead(5)==LOW);
    delay(1000);
      if(digitalRead(A3) == HIGH){
          if(Stop()==1)
          return 0;
        }
    ekran_cykle("poprawne cisnienie",x);
    delay(1000);
      if(digitalRead(A3) == HIGH){
          if(Stop()==1)
          return 0;
        }
    ekran_cykle("zawor pompy zamk.",x);
    digitalWrite(12, HIGH);    
    digitalWrite(8, HIGH);   //ciśnienie w normie
  x++;
  }
  while(x <= ile_razy);
  return 1;
}

void Reaktor(int ti,int ile_razy){
  bool pokaz_menu = true;
    digitalWrite(8, LOW);
    ekran("pompa on");                      //otwarcie pompy i zaworu
    delay(1000);
      if(digitalRead(A3) == HIGH){
          if(Stop()==1)
          return 0;
        }
    digitalWrite(12, LOW);
    ekran("zawor pompy otwarty");
    delay(1000);
    ekran("regulacja cisnienia");
      do{
        delay(100);
          if(digitalRead(A3) == HIGH){
          if(Stop()==1)
          return 0;
        }
      }
      while(digitalRead(5)==LOW);
    delay(1000);
      if(digitalRead(A3) == HIGH){
          if(Stop()==1)
          return 0;
        }
    ekran("cisnienie poprawne");
    delay(1000);
      if(digitalRead(A3) == HIGH){
          if(Stop()==1)
          return 0;
        }
   
    ekran("zawor pompy zamk.");                //zamknięcie zaworu i pompy
    digitalWrite(12, HIGH);
    delay(1000);
      if(digitalRead(A3) == HIGH){
          if(Stop()==1)
          return 0;
        }
    ekran("wylaczenie pompy");
    digitalWrite(8, HIGH);
    delay(1000);
      if(digitalRead(A3) == HIGH){
          if(Stop()==1)
          return 0;
        }
    ekran("generator paliwa on");            //generator paliwa on
    digitalWrite(9, LOW);
    delay(1000);
      if(digitalRead(A3) == HIGH){
          if(Stop()==1)
          return 0;
        }
    ekran("funkcja paliwo");
    delay(1000);
      if(digitalRead(A3) == HIGH){
          if(Stop()==1)
          return 0;
        }
    if(Paliwo(ile_razy,1)==0)                                         //funkcja paliwo
    return 0;
    delay(1000);
      if(digitalRead(A3) == HIGH){
          if(Stop()==1)
          return 0;
        }
    ekran("zawor pompy otwarty");                 //otwarcie zaworu pompy i wyłączenie generatora pompy            
    digitalWrite(8,LOW);
    delay(1000);
    digitalWrite(12,LOW);
      if(digitalRead(A3) == HIGH){
          if(Stop()==1)
          return 0;
        }
    ekran("generator paliwa off");
    digitalWrite(9,HIGH);
    delay(1000);
      if(digitalRead(A3) == HIGH){
          if(Stop()==1)
          return 0;
        }
    ekran("poczekaj 10 min");
    delay(1000);
      if(digitalRead(A3) == HIGH){
         if(Stop()==1)
          return 0; 
        }
    for(int ta = 7200; ta>=1;ta--){
      if(ta%10==0)
      ekran_cyfra_i_tekst("odpompowywnie",ta/10);
      delay(100);
        if(digitalRead(A3) == HIGH){
          if(Stop()==1)
          return 0;
        }
    }                                                  //czekanie 10 min
    ekran("pompa off");
    digitalWrite(8, HIGH);
    digitalWrite(12, HIGH);
   ekran_fuzja("rozpocznij fuzje");
    do{
        if(digitalRead(A3) == HIGH){
          if(Stop()==1)
          return 0;
        }
    }
    while(digitalRead(4)==LOW);
    if(digitalRead(5)==LOW){
      ekran("nieszczelna komora");
      delay(1000);
      ekran("powrot do startu");
      return 0;
    }
    else{
      do{
      if(fuzja()==0)
      return 0;
      ti--;
      }
      while(ti>1);
      ekran("wykonano maks fuzji");
      delay(1000);
      ekran("powrot do startu");
    }
}

int fuzja(){
    pozwolenie_na_kont = true;
    if(digitalRead(A3) == HIGH){
          if(Stop()==1)
          return 0;
        }
        int t=5;
  while(t>=1){
    ekran_cyfra_i_tekst("fuzja za",t);
    t--;
    delay(1000);
      if(digitalRead(A3) == HIGH){
          if(Stop()==1)
          return 0;
        }
  }

  digitalWrite(13, HIGH);                                           //wysokie napiecie
  for(t = 1200; t>=1;t--){
      if(t%10==0)
      ekran_cyfra_i_tekst("praca",t/10);
      delay(100);
        if(digitalRead(A3) == HIGH){
          if(Stop()==1)
          return 0;
        }
    }                                                  //czekaj 3m
  ekran("wylaczenie");                                    //wyłączenie
  digitalWrite(13, LOW);
  for(t = 600; t>=1;t--){
      if(t%10==0)
      ekran_cyfra_i_tekst("odpoczynek",t/10);
      delay(100);
        if(digitalRead(A3) == HIGH){
          if(Stop()==1)
          return 0;
        }
    }  
  digitalWrite(13, HIGH);                                           //wysokie napiecie
  for(t = 1200; t>=1;t--){
      if(t%10==0)
      ekran_cyfra_i_tekst("praca",t/10);
      delay(100);
        if(digitalRead(A3) == HIGH){
          if(Stop()==1)
          return 0;
        }
    }                                                  //czekaj 3m
  ekran("wylaczenie");                                    //wyłączenie
  digitalWrite(13, LOW);
  delay(1000);
    if(digitalRead(A3) == HIGH){
          if(Stop()==1)
          return 0;     
        }
  ekran("generator paliwa on");                     //generator paliwa
  digitalWrite(9, LOW);
  delay(1000);
  if(Paliwo(1,1)==0)
  return 0;
    if(digitalRead(A3) == HIGH){
         if(Stop()==1)
          return 0;
        }
  ekran("generator paliwa off");
  digitalWrite(9, HIGH);
  delay(1000);
    if(digitalRead(A3) == HIGH){
          if(Stop()==1)
          return 0;
        }
  ekran("zawor pompy otwarty");
  digitalWrite(8, LOW);
  digitalWrite(12, LOW);
  delay(1000);
  do{
    ekran("regulacja cisnienia");
    delay(100);
      if(digitalRead(A3) == HIGH){
          if(Stop()==1)
          return 0;
        }
  }
  while(digitalRead(5)==LOW);
  ekran("czekaj 6 min");              //czekaj 10 min
  delay(1000);
    digitalWrite(8, LOW);
    if(digitalRead(A3) == HIGH){
          if(Stop()==1)
          return 0; 
        }
  for(t = 7200; t>=1;t--){
      if(t%10==0)
      ekran_cyfra_i_tekst("odpompowywanie",t/10);
      delay(100);
        if(digitalRead(A3) == HIGH){
          if(Stop()==1)
          return 0;
        }
    }    
  ekran("zawor pompy zamk.");
  digitalWrite(12, HIGH);
  ekran("pompa off");
  digitalWrite(8,HIGH)  ;
  return 1;
}

void zmiana_stanu(int urzadzenie){
  

    if(digitalRead(urzadzenie) == HIGH){
      digitalWrite(urzadzenie, LOW);
      delay(250);
    }
    else{
      digitalWrite(urzadzenie, HIGH);
      delay(250);
    }
}

void tryb_serwisowy(int pozycja,bool wyswietl){
  delay(1000);
  while(digitalRead(A3) == LOW){

  if(pozycja == 0 && wyswietl == true){
    ekran_serwis(" ","czujniki","pompa",7);
    wyswietl = false;
  }
  else if(pozycja == 1 && wyswietl == true){                                     //wyswietlanie
    ekran_serwis("czujniki","pompa","generator",8);
    wyswietl = false;
  }
  else if(pozycja == 2 && wyswietl == true){
    ekran_serwis("pompa","generator","zawor_awaryjny",9);
    wyswietl = false;
  }
  else if(pozycja == 3 && wyswietl == true){
    ekran_serwis("generator","zawor_awaryjny","zawor_paliwa",10);
    wyswietl = false;
  }
  else if(pozycja == 4 && wyswietl == true){
    ekran_serwis("zawor_awaryjny","zawor_paliwa","zawor_pompy",11);
    wyswietl = false;
  }
  else if(pozycja == 5 && wyswietl == true){
    ekran_serwis("zawor_paliwa","zawor_pompy","fuzja",12);
    wyswietl = false;
  }
  else if(pozycja == 6 && wyswietl == true){
    ekran_serwis("zawor_pompy","fuzja"," ",13);
    wyswietl = false;
  }                                                                         //koniec wyswietlania

  if(digitalRead(2) == HIGH && pozycja < 6){                                //poruszanie sie po menu
    pozycja ++;
    delay(250);
    wyswietl = true;
  }
  if(digitalRead(3) == HIGH && pozycja > 0){
    pozycja --;
    delay(250);
    wyswietl = true;
  }                                                                         //koniec poruszania

  if(digitalRead(4) == HIGH && pozycja == 0){
    ekran_czujniki();
    wyswietl == true;
  }
  else if(digitalRead(4) == HIGH && pozycja == 1){                               //zmiana stanu
    zmiana_stanu(8);
    wyswietl = true;
  }
  else if(digitalRead(4) == HIGH && pozycja == 2){
    zmiana_stanu(9);
    wyswietl = true;
  }
  else if(digitalRead(4) == HIGH && pozycja == 3){
    zmiana_stanu(10);
    wyswietl = true;
  }
  else if(digitalRead(4) == HIGH && pozycja == 4){
    zmiana_stanu(11);
    wyswietl = true;
  }
  else if(digitalRead(4) == HIGH && pozycja == 5){
    zmiana_stanu(12);
    wyswietl = true;
  }
  else if(digitalRead(4) == HIGH && pozycja == 6){
    zmiana_stanu(13);
    wyswietl = true;
  }                                                                         //koniec zmiany stanu
  }
}

void setup() {
  pinMode(A3, INPUT_PULLUP);  //przycisk +000
  pinMode(2, INPUT_PULLUP);   //przycisk 0+00
  pinMode(3, INPUT_PULLUP);   //przycisk 00+0
  pinMode(4, INPUT_PULLUP);   //przycisk 000+
  pinMode(5, INPUT_PULLUP);   //czujnik ciśnienia
  pinMode(6, INPUT_PULLUP);   //czujnik paliwo min
  pinMode(7, INPUT_PULLUP);   //czujnik paliwo max
  pinMode(8, OUTPUT);     //pompa
  pinMode(9, OUTPUT);     //generator paliwa
  pinMode(10, OUTPUT);    //zawór awaryjny powietrze
  pinMode(11, OUTPUT);    //zawór paliwa
  pinMode(12, OUTPUT);    //zawór pompy
  pinMode(13, OUTPUT);    //fuzja
  Serial.begin(9600);
  digitalWrite(8, HIGH);
  digitalWrite(9, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(11, HIGH);
  digitalWrite(12, HIGH);
  digitalWrite(13, LOW);
  lcd.begin(20,4);
  lcd.init();
  lcd.backlight();

}

void loop() {

   if(pokaz_menu == true){
    ekran_menu("Reaktor Fuzyjny v2 ");
    pokaz_menu = false;
  }

  if(digitalRead(3) == HIGH){
  Reaktor(3,3); //ile cykli fuzji, ile cykli przedmuchu
  ekran_pusty("wykonano fuzje");
  delay(2000);
 pokaz_menu = true;
  }

  else if(digitalRead(2) == HIGH && pozwolenie_na_kont == true){     //kont true
  Reaktor(3,1);
  ekran_pusty("wykonano fuzje");
  delay(2000);
 pokaz_menu = true;
  }
  else if(digitalRead(2) == HIGH && pozwolenie_na_kont == false){    //kont false
  ekran_menu("nie wolno kont");
  delay(2000);
 pokaz_menu = true;
  }
  else if(digitalRead(4) == HIGH){
    tryb_serwisowy(1,true);
    digitalWrite(8,HIGH);
  digitalWrite(9,HIGH);
  digitalWrite(10,HIGH);
  digitalWrite(11,HIGH);
  digitalWrite(12,HIGH);
  digitalWrite(13,LOW);
    pokaz_menu=true; 
    }
}