#include <iostream>
#include <cstdio>
#include <iomanip>
#include <fstream>
#include <cstdlib>


using namespace std;
#pragma pack(push, 1)
struct odpowiedzi{
    int zerowanie_RGB[3]={0,0,0};
    int czy_zamienic_RGB[3]={0,0,0};
    int B,G,R;

};

struct czy{
    bool SI[16]={0,1,0,0,1,1,1,1,0,0,1,1,1,1,1,1};
};
#pragma pack(pop)
void zapis_naglowek(odpowiedzi zamiana,string koniec,string poczatek){
    czy SPR;
    int height,width;
    char zero=0;
    ifstream plikp(poczatek+".bmp", ios::binary);
    ofstream plikk( koniec+".bmp", ios::binary );
    int koniec_danych;

    plikp.seekg(10);
    plikp.read((char*)&koniec_danych,sizeof(int));
    plikp.seekg(18);
    plikp.read((char*)&height,sizeof(int));
    plikp.seekg(22);
    plikp.read((char*)&width,sizeof(int));
    plikp.seekg(0);
    plikk.seekp(0);
    for(int i =0 ; i<16;i++){

            if(SPR.SI[i]==0){
                short  temp;
                plikp.read((char*)&temp,sizeof(short));
                plikk.write((char*)&temp,sizeof(short));
        }else{
                int  temp ;
                plikp.read((char*)&temp,sizeof(int));
                plikk.write((char*)&temp,sizeof(int));
        }
    }

    int wyrownanie = (width*3)%4 ?4-(width*3)%4:0;
    if(width % 4) width += 4 - (width % 4);

    for(int i = 0; i < height; i++,plikk.seekp(wyrownanie,ios_base::cur))
    for(int j = 0; j < width; j++){
    char temp;
        if(zamiana.zerowanie_RGB[0]==true){
                plikk.write(( const char * ) & zero, sizeof (char));
                plikp.seekg(sizeof(char),ios_base::cur);
           } else if(zamiana.czy_zamienic_RGB[0]==0){
                    plikp.read((char*)&temp ,sizeof(char));
                    plikk.write(( const char * ) & temp,sizeof (char));
                       } else{
                           plikk.write(( const char * ) & zamiana.B, sizeof (char));
                            plikp.seekg(sizeof(char),ios_base::cur);
                       }
                       if(zamiana.zerowanie_RGB[1]==true){
                plikk.write(( const char * ) & zero, sizeof (char));
                plikp.seekg(sizeof(char),ios_base::cur);
           } else if(zamiana.czy_zamienic_RGB[1]==0){
                    plikp.read((char*)&temp ,sizeof(char));
                    plikk.write(( const char * ) & temp,sizeof (char));
                       } else{
                           plikk.write(( const char * ) & zamiana.G, sizeof (char));
                            plikp.seekg(sizeof(char),ios_base::cur);
                       }
                       if(zamiana.zerowanie_RGB[2]==true){
                plikk.write(( const char * ) & zero, sizeof (char));
                plikp.seekg(sizeof(char),ios_base::cur);
           } else if(zamiana.czy_zamienic_RGB[2]==0){
                    plikp.read((char*)&temp ,sizeof(char));
                    plikk.write(( const char * ) & temp,sizeof (char));
                       } else{
                           plikk.write(( const char * ) & zamiana.R, sizeof (char));
                            plikp.seekg(sizeof(char),ios_base::cur);
                       }

}

    plikk.close();
    plikp.close();

}
void cza_bia(string koniec,string poczatek){
    czy SPR;
    int height,width;
    char zero=0;
    ifstream plikp(poczatek+".bmp", ios::binary);
    ofstream plikk( koniec+".bmp", ios::binary );
    int koniec_danych;

    plikp.seekg(10);
    plikp.read((char*)&koniec_danych,sizeof(int));
    plikp.seekg(18);
    plikp.read((char*)&height,sizeof(int));
    plikp.seekg(22);
    plikp.read((char*)&width,sizeof(int));
    plikp.seekg(0);
    plikk.seekp(0);
    for(int i =0 ; i<16;i++){

            if(SPR.SI[i]==0){
                short  temp;
                plikp.read((char*)&temp,sizeof(short));
                plikk.write((char*)&temp,sizeof(short));
        }else{
                int  temp ;
                plikp.read((char*)&temp,sizeof(int));
                plikk.write((char*)&temp,sizeof(int));
        }
    }

    int wyrownanie = (width*3)%4 ?4-(width*3)%4:0;
    if(width % 4) width += 4 - (width % 4);
    char temp[3];
    int a=0;
    for(int i = 0; i < height; i++,plikk.seekp(wyrownanie,ios_base::cur))
    for(int j = 0; j < width; j++){
                    plikp.read((char*)&temp[a],sizeof(char));
                    plikp.read((char*)&temp[a+1] ,sizeof(char));
                    plikp.read((char*)&temp[a+2],sizeof(char));
                   char mieszanka=(char)(0.229*temp[a] + 0.587*temp[a+1] + 0.114*temp[a+2]);

                    plikk.write(( const char * ) & mieszanka, sizeof  (char));

                    plikk.write(( const char * ) & mieszanka, sizeof  (char));

                    plikk.write(( const char * ) & mieszanka, sizeof  (char));
                    a=0;
            }
    plikk.close();
    plikp.close();
}
void wybor(int odp,string koniec,string poczatek){
    odpowiedzi zamiana;
    system("cls");
    if(odp==1){
        cout<<"+-----------------------------------+"<<endl;
        cout<<"|Czy chcesz zmienic niebieski kolor?|"<<endl;
        cout<<"|               [1]tak              |"<<endl;
        cout<<"|               [0]nie              |"<<endl;
        cout<<"+-----------------------------------+"<<endl;
        while( !( cin >> zamiana.czy_zamienic_RGB[0] && zamiana.czy_zamienic_RGB[0]<=1 && zamiana.czy_zamienic_RGB[0]>=0)) {
        system("cls");
        cin.clear();
        cin.sync();
        cout<<"+-----------------------------------+"<<endl;
        cout<<"|Czy chcesz zmienic niebieski kolor?|"<<endl;
        cout<<"|               [1]tak              |"<<endl;
        cout<<"|               [0]nie              |"<<endl;
        cout<<"+-----------------------------------+"<<endl;
                }
        if(zamiana.czy_zamienic_RGB[0]==true){
            cout<<"podaj wartosc od 0 do 255"<<endl;
            cout<<"B:  ";
                while(!(cin >> zamiana.B && zamiana.B <= 255  && zamiana.B >= 0 )){
            system("cls");
            cin.clear();
            cin.sync();
            cout<<"podaj wartosc od 0 do 255"<<endl;
            cout<<"B:  ";
             }
        }
        system("cls");
        cout<<"+----------------------------------+"<<endl;
        cout<<"| Czy chcesz zmienic zielony kolor?|"<<endl;
        cout<<"|               [1]tak             |"<<endl;
        cout<<"|               [0]nie             |"<<endl;
        cout<<"+----------------------------------+"<<endl;
        while( !( cin >> zamiana.czy_zamienic_RGB[1] && zamiana.czy_zamienic_RGB[1]<=1 && zamiana.czy_zamienic_RGB[1]>=0)) {
        system("cls");
        cin.clear();
        cin.sync();
        cout<<"+----------------------------------+"<<endl;
        cout<<"| Czy chcesz zmienic zielony kolor?|"<<endl;
        cout<<"|               [1]tak             |"<<endl;
        cout<<"|               [0]nie             |"<<endl;
        cout<<"+----------------------------------+"<<endl;
                }
         if(zamiana.czy_zamienic_RGB[1]==true){
            cout<<"podaj wartosc od 0 do 255"<<endl;
            cout<<"G:  ";
             while(!(cin >> zamiana.G && zamiana.G <= 255  && zamiana.G >= 0 )){
            system("cls");
            cin.clear();
            cin.sync();
            cout<<"podaj wartosc od 0 do 255"<<endl;
            cout<<"G:  ";
             }
        }
        system("cls");
        cout<<"+----------------------------------+"<<endl;
        cout<<"|Czy chcesz zmienic czerwony kolor?|"<<endl;
        cout<<"|               [1]tak             |"<<endl;
        cout<<"|               [0]nie             |"<<endl;
        cout<<"+----------------------------------+"<<endl;
        while( !( cin >> zamiana.czy_zamienic_RGB[2] && zamiana.czy_zamienic_RGB[2]<=1 && zamiana.czy_zamienic_RGB[2]>=0)) {
        system("cls");
        cin.clear();
        cin.sync();
        cout<<"+----------------------------------+"<<endl;
        cout<<"|Czy chcesz zmienic czerwony kolor?|"<<endl;
        cout<<"|               [1]tak             |"<<endl;
        cout<<"|               [0]nie             |"<<endl;
        cout<<"+----------------------------------+"<<endl;
                }
         if(zamiana.czy_zamienic_RGB[2]==true){
            cout<<"podaj wartosc od 0 do 255"<<endl;
            cout<<"R:  ";
             while(!(cin >> zamiana.R && zamiana.R <= 255  && zamiana.R >= 0 )){
            system("cls");
            cin.clear();
            cin.sync();
            cout<<"podaj wartosc od 0 do 255"<<endl;
            cout<<"R:  ";
        }
         }

        system("cls");
        zapis_naglowek(zamiana,koniec,poczatek);

    }else{
        system("cls");
        cout<<"+----------------------------------+"<<endl;
        cout<<"|Czy chcesz usunac niebieski kolor?|"<<endl;
        cout<<"|               [1]tak             |"<<endl;
        cout<<"|               [0]nie             |"<<endl;
        cout<<"+----------------------------------+"<<endl;
        while( !( cin >> zamiana.zerowanie_RGB[0] && zamiana.zerowanie_RGB[0]<=1 && zamiana.zerowanie_RGB[0]>=0)) {
        system("cls");
        cin.clear();
        cin.sync();
        cout<<"+----------------------------------+"<<endl;
        cout<<"|Czy chcesz usunac niebieski kolor?|"<<endl;
        cout<<"|               [1]tak             |"<<endl;
        cout<<"|               [0]nie             |"<<endl;
        cout<<"+----------------------------------+"<<endl;
                }
        system("cls");
        cout<<"+----------------------------------+"<<endl;
        cout<<"|Czy chcesz usunac zielony kolor?  |"<<endl;
        cout<<"|               [1]tak             |"<<endl;
        cout<<"|               [0]nie             |"<<endl;
        cout<<"+----------------------------------+"<<endl;
        while( !( cin >> zamiana.zerowanie_RGB[1] && zamiana.zerowanie_RGB[1]<=1 && zamiana.zerowanie_RGB[1]>=0)) {
        system("cls");
        cin.clear();
        cin.sync();
        cout<<"+----------------------------------+"<<endl;
        cout<<"|Czy chcesz usunac zielony kolor?  |"<<endl;
        cout<<"|               [1]tak             |"<<endl;
        cout<<"|               [0]nie             |"<<endl;
        cout<<"+----------------------------------+"<<endl;
                }
            system("cls");
        cout<<"+----------------------------------+"<<endl;
        cout<<"|Czy chcesz usunac czerwony kolor? |"<<endl;
        cout<<"|               [1]tak             |"<<endl;
        cout<<"|               [0]nie             |"<<endl;
        cout<<"+----------------------------------+"<<endl;
        while( !( cin >> zamiana.zerowanie_RGB[2] && zamiana.zerowanie_RGB[2]<=1 && zamiana.zerowanie_RGB[2]>=0)) {
        system("cls");
        cin.clear();
        cin.sync();
        cout<<"+----------------------------------+"<<endl;
        cout<<"|Czy chcesz usunac czerwony kolor? |"<<endl;
        cout<<"|               [1]tak             |"<<endl;
        cout<<"|               [0]nie             |"<<endl;
        cout<<"+----------------------------------+"<<endl;
                }
        system("cls");
        zapis_naglowek(zamiana,koniec,poczatek);
    }

}


int main(){
    odpowiedzi zamiana;
    ifstream plik;
    string poczatek,koniec;

    int wyrownanie;
    cout<<"+----------------------------------------WITAJ-----------------------------------------+"<<endl;
    cout<<"|Wpisz nazwe pliku jaki ma zostac zamieniony (UWAGA MUSI ON BYC W FOLDERZE Z PROGRAMEM)|"<<endl;
    cout<<"+--------------------------------------------------------------------------------------+"<<endl;

    cin>>poczatek;
    plik.open(poczatek+".bmp",ios::binary);
    while  (!plik){
        cout << "Plik \"" << poczatek <<"\" nie istnieje!" << endl;
        plik.close();
        cout << "Podaj nazwe pliku: ";
        cin >> poczatek;
        plik.open(poczatek+".bmp", ios::binary);
    }

    cout<<"+--------------------------------------------------+"<<endl;
    cout<<"|wpisz nazwe pliku w jakim do jakiego wpisac zmiany|"<<endl;
    cout<<"+--------------------------------------------------+"<<endl;

    cin>>koniec;
    ofstream plikk( koniec+".bmp", ios::binary );

    system("cls");



    int odp;
    cout<<"+------------Co chcesz zmienic w tym zdjeciu?------------+"<<endl;
    cout<<"|                  [1]Zmienic skladowe                   |"<<endl;
    cout<<"|                  [2]Wyzerowac skladowe                 |"<<endl;
    cout<<"|                  [3]Zrobic je czarno-biale             |"<<endl;
    cout<<"|                  [0]Nic                                |"<<endl;
    cout<<"+--------------------------------------------------------+"<<endl;
    while( !( cin >> odp && odp<=3 && odp>=0)) {
        cout<<"Moze jednak wybierzesz cos z menu ? :)"<<endl;
        cin.clear();
        cin.sync();
    }
    system("cls");
    switch(odp){
    case 1:
        wybor(odp, koniec,poczatek);
        break;
    case 2:
        wybor(odp, koniec,poczatek);
        break;
    case 3:
      cza_bia(koniec,poczatek);
        break;
    default:
        break;
    }
    system("cls");

    plik.close();

    return 0;

}
