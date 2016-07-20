#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int autorstvo;

class Ucenik
    {
        private:
            int junski_rok;
        public:
            int ocjene[5][20];
            void postaviJunskiRok(int moze);
            int izdvojiJunskiRok();
            double izracunajProsjekOcjenaOpstiUspjeh(int razred);
            double izracunajProsjekOcjenaPosebanUspjeh(int razred);
            double izracunajBrojBodovaOpstiUspjeh();
            double izracunajBrojBodovaPosebanUspjeh();
            double izracunajUkupanBrojBodova();
    };

void vrednus();
void prilog1();
double zaokruzivanjeBroja(double prosjek);
double apsolutnaVrijednostBroja(double broj);
double izracunajUkupanBrojBodova();
void unos(Ucenik &uc);
void rezultati(Ucenik &uc);
void pcela();

void vrednus()
    {
        cout<<"                                                                                ";
        cout<<"                          Vrednus (¢) Uncopyright 2010                          ";
        cout<<"                  Ovaj program nije zasticen autorskim pravima.                 ";
        cout<<"                                                                                ";
        cout<<"     Vrednus je program za VREDNovanje USpjeha u osnovnoj skoli. Namijenjen je  ";
        cout<<"clanovima komisija za upis i kandidatima koji konkurisu za upis u prvi razred   ";
        cout<<"srednjih skola u Republici Srpskoj. Izracunava ukupan broj bodova na osnovu op- ";
        cout<<"steg i posebnog uspjeha ostvarenog u osnovnoj skoli. Prema dobijenom ukupnom    ";
        cout<<"broju bodova utvrdjuje se redoslijed kandidata za upis.                         ";
        cout<<"                                                                                ";
        cout<<"                         Za nastavak pritisnite ENTER!\n";
        cout<<"                                       ";
        getchar();
        system("clear");
    }

void prilog1()
    {
        cout<<"           PREDMETI IZ OSMOG I DEVETOG RAZREDA OSNOVNE SKOLE KOJI SE\n";
        cout<<"                            POSEBNO BODUJU ZA UPIS\n\n";
        cout<<"GIMNAZIJA - OPSTI SMJER: Srpski jezik, strani jezik, matematika, fizika i hemi-\nja;\n\n";
        cout<<"GIMNAZIJA - DRUSTVENO-JEZICKI SMJER: Srpski jezik, strani jezik, matematika, \nistorija i informatika;\n\n";
        cout<<"GIMNAZIJA - PRIRODNO-MATEMATICKI SMJER: Srpski jezik, strani jezik, matematika, \nfizika i informatika;\n\n";
        cout<<"GIMNAZIJA - RACUNARSKO-INFORMATICKI SMJER: Srpski jezik, strani jezik, matemati-\nka, fizika i informatika;\n\n";
        cout<<"POLJOPRIVREDA I PRERADA HRANE: Srpski jezik, strani jezik, hemija, biologija \ninformatika;\n\n";
        cout<<"SUMARSTVO I OBRADA DRVETA: Srpski jezik, matematika, biologija, hemija i infor-\nmatika;\n\n";
        cout<<"                         Za nastavak pritisnite ENTER!\n";
        cout<<"                                       ";
        getchar();
        system("clear");
        cout<<"GEOLOGIJA, RUDARSTVO I METALURGIJA: Srpski jezik, strani jezik, matematika, fi-\nzika i hemija;\n\n";
        cout<<"MASINSTVO I OBRADA METALA: Srpski jezik, strani jezik, matematika, fizika i \ninformatika;\n\n";
        cout<<"ELEKTROTEHNIKA: Srpski jezik, strani jezik, matematika, fizika i informatika;\n\n";
        cout<<"HEMIJA, NEMETALI I GRAFICARSTVO: Srpski jezik, strani jezik, matematika, fizika \ni hemija;\n\n";
        cout<<"TEKSTILSTVO I KOZARSTVO: Srpski jezik, strani jezik, fizika, hemija i biologija;\n\n";
        cout<<"GEODEZIJA I GRADJEVINARSTVO: Srpski jezik, strani jezik, matematika, fizika i \ninformatika;\n\n";
        cout<<"SAOBRACAJ: Srpski jezik, matematika, fizika, geografija i informatika;\n\n";
        cout<<"UGOSTITELJSTVO I TURIZAM: Srpski jezik, strani jezik, istorija, geografija i \ninformatika;\n\n";
        cout<<"                         Za nastavak pritisnite ENTER!\n";
        cout<<"                                       ";
        getchar();
        system("clear");
        cout<<"EKONOMIJA, PRAVO I TRGOVINA: Srpski jezik, strani jezik, matematika, istorija i \ngeografija;\n\n";
        cout<<"ZDRAVSTVO: Srpski jezik, strani jezik, fizika, hemija i biologija;\n\n";
        cout<<"OSTALE DJELATNOSTI: Srpski jezik, strani jezik, fizika, hemija i informatika;\n\n";
        cout<<"KULTURA, UMJETNOST I INFORMISANJE: Srpski jezik, strani jezik, muzicka kultura, \nlikovna kultura i informatika.\n\n";
        cout<<"                         Za nastavak pritisnite ENTER!\n";
        cout<<"                                       ";
        getchar();
        system("clear");
    }

double zaokruzivanjeBroja(double prosjek)
    {
        double p;
        p=prosjek*100;
        if (p-(int)(p)<0.5)
            return (double)(int)(p)/100;
                else
                    if (p-(int)(p)>0.5)
                        return (double)(int)(p)/100+0.01;
                            else
                                if (p-(int)(p)==0.5)
                                    {
                                        if ((int)(p)%2==0)
                                        return (double)(int)(p)/100;
                                            else
                                                return (double)(int)(p)/100+0.01;
                                    }
    }

double apsolutnaVrijednostBroja(double broj)
    {
        if (broj>=0)
            return broj;
                else
                    return broj*(-1);
    }

double izracunajUkupanBrojBodova(Ucenik &uc)
    {
        double b;
        b=uc.izracunajBrojBodovaOpstiUspjeh()+uc.izracunajBrojBodovaPosebanUspjeh();
        if (b<60)
            uc.postaviJunskiRok(0);
                else
                    uc.postaviJunskiRok(1);
        return b;
    }

void unos(Ucenik &uc)
    {
        system("clear");
        int i;
        int j;
        int k;
        for(int i=1;i<=4;i++)
                {
                    uc.ocjene[i][1]=0;
                    j=0;
                    int l;
                    int greske[20];
                    for (l=1;l<=20;l++)
                        greske[l]=0;
                    cout<<"Unesite ocjene brojcanih vrijednosti 2, 3, 4 ili 5! Da ponistite poslednju une-\nsenu ocjenu unesite broj -1! Kada unosite ocjenu iz predmeta koji se posebno \nboduje (osmi i deveti razred), ispred brojcane vrijednosti ocjene dopisite znak\nminus (unosite brojcane vrijednosti -2, -3, -4, ili -5)! Za kraj unosa unesite\nbrojcanu vrijednost 0!\n\n\n";
                    cout<<"\n\nUnesite ocjene koje kandidat ima u "<<i+5<<"-om razredu (na kraju svakog unosa pritisni-\nte ENTER):\n";
                    uc.ocjene[i][j]=-1;
                    while (uc.ocjene[i][j]!=0)
                        {
                            j++;
                            cout<<"                                       ";
                            cin>>uc.ocjene[i][j];
                            if (((apsolutnaVrijednostBroja(uc.ocjene[i][j])>5) || (uc.ocjene[i][j]==1)) && (uc.ocjene[i][j]!=-1))
                                {
                                    cout<<"\nUneseni broj "<<uc.ocjene[i][j]<<" nije brojcana vrijednost ocjene!\n";
                                    greske[j]=1;
                                    if ((i==1) && (j==1) && (autorstvo==9) && (uc.ocjene[1][1]==101020))
                                        autorstvo--;
                                    if ((i==2) && (j==1) && (autorstvo==7) && (uc.ocjene[2][1]==305080))
                                        autorstvo--;
                                    if ((i==3) && (j==1) && (autorstvo==5) && (uc.ocjene[3][1]==130210))
                                        autorstvo--;
                                    if ((i==4) && (j==1) && (autorstvo==3) && (uc.ocjene[4][1]==340550))
                                        autorstvo--;
                                }
                            if ((uc.ocjene[i][j]==-1) && (j-1>0))
                                {
                                    if ((i==1) && (j==2) && (autorstvo==8) && (uc.ocjene[1][1]==101020))
                                        autorstvo--;
                                    if ((i==2) && (j==2) && (autorstvo==6) && (uc.ocjene[2][1]==305080))
                                        autorstvo--;
                                    if ((i==3) && (j==2) && (autorstvo==4) && (uc.ocjene[3][1]==130210))
                                        autorstvo--;
                                    if ((i==4) && (j==2) && (autorstvo==2) && (uc.ocjene[4][1]==340550))
                                        autorstvo--;
                                    greske[j-1]=0;
                                    j-=2;
                                }
                            k=0;
                            for (l=1;l<=20;l++)
                                if (greske[l]!=0)
                                    k++;
                            if ((uc.ocjene[i][j]==0) && (k!=0))
                                        {
                                            i--;
                                            uc.ocjene[i][j]=0;
                                        }
                        }
                    if ((uc.ocjene[i][1]!=0) && (k==0))
                        {
                            cout<<"\nUnesene su ocjene: ";
                            for (l=2;l<j;l++)
                                cout<<apsolutnaVrijednostBroja(uc.ocjene[i][l-1])<<", ";
                            cout<<apsolutnaVrijednostBroja(uc.ocjene[i][l-1])<<"!\n\n";
                        }
                            else
                                if ((uc.ocjene[i][1]==0) && (k==0))
                                    cout<<"\nNisu unesene ocjene!\n\n";
                                        else
                                            if (k!=0)
                                                cout<<"\nNisu ispravno unesene ocjene!\n\n";
                    if ((k==0) && (uc.ocjene[i][1]!=0))
                        cout<<"\nU "<<i+5<<"-om razredu kandidat ima prosjecnu ocjenu opsteg uspjeha "<<uc.izracunajProsjekOcjenaOpstiUspjeh(i)<<"!\n\n";
                    cout<<"                         Za nastavak pritisnite ENTER!\n";
                    cout<<"                                       ";
                    getchar();
                    getchar();
                    system("clear");
                  }
    }


void rezultati(Ucenik &uc)
    {
        double opsti_uspjeh;
        opsti_uspjeh=uc.izracunajBrojBodovaOpstiUspjeh();
        if (opsti_uspjeh>=20)
            cout<<"Na osnovu opsteg uspjeha kandidat je osvojio "<<opsti_uspjeh<<" bodova!\n";
                else
                    if (opsti_uspjeh==0)
                        cout<<"Nisu unesene ucjene!\n\n";
                            else
                                cout<<"Nisu unesene sve ocjene!\n";
        double poseban_uspjeh;
        poseban_uspjeh=uc.izracunajBrojBodovaPosebanUspjeh();
        if (poseban_uspjeh>=8)
            cout<<"Na osnovu posebnog uspjeha kandidat je osvojio "<<poseban_uspjeh<<" bodova!\n\n";
                else
                    if ((opsti_uspjeh!=0) && (poseban_uspjeh<8) && (poseban_uspjeh!=0))
                        cout<<"Nisu unesene sve ocjene iz predmeta koji se posebno boduju za upis!\n\n";
                            else
                                if ((poseban_uspjeh==0) && (opsti_uspjeh!=0))
                                    cout<<"Nisu unesene ocjene iz predmeta koji se posebno boduju za upis!\n\n";
        if((opsti_uspjeh>=20) && (poseban_uspjeh>=8))
            {
                cout<<"Na osnovu oba kriterijuma kandidat je osvojio "<<izracunajUkupanBrojBodova(uc)<<" bodova!\n\n";
                if (uc.izdvojiJunskiRok()==0)
                    cout<<"Kandidat se ne moze upisati u gimnaziju i strucnu tehnicku skolu u junskom upis-\nnom roku!\n\n";
            }
        cout<<"                         Za nastavak pritisnite ENTER!\n";
        cout<<"                                       ";
        getchar();
        system("clear");
    }

void pcela()
    {
        cout<<"                                               :syhhhhhy/\n";
        cout<<"                                             /dy/::::::/ds\n";
        cout<<"                                            sd/:::::::::/M.\n";
        cout<<"                                           +m::::::::::::N:\n";
        cout<<"                            `:/+:`        .N+::::::::::::M-\n";
        cout<<"                          .yho++oyh+`     +m::::::::::::+N`\n";
        cout<<"                         .mo:::::::sd+    hy::::::::::::yy\n";
        cout<<"                         sh::::::::::yh-  mo::::::::::::N:\n";
        cout<<"                         yh:::::::::::+m+ mo:::::::::::yh\n";
        cout<<"                         -N/:::::::::::/dyNo::::::::::/N-\n";
        cout<<"                          +m/::::::::::::yMs::::::::::ds\n";
        cout<<"                   ./oyhmdsom+::::::::::::dd:::::::::sm`\n";
        cout<<"              `-+yyso/:..-oh-hy:::::::::::sNy:::::::/N-\n";
        cout<<"           `:os+:.`        +:`odo:::::::::/Noy::::::m+\n";
        cout<<"     .:/+shsyso++/-`        o` .sh+::::::::moos::::hy\n";
        cout<<"`--/o/-:yNh-    `.:++:`     .o:  -sh+::::::yh:os::sd`\n";
        cout<<"dNNM:  yMMMs        `-++.   ./hh/:.-sho::::/N::soom. `.-/ooss+:---.`\n";
        cout<<"ymNd-  .+s+.           .+o:ho/--:+yo..ohs/::ds::hN+://--/hmmmdo----::::`\n";
        cout<<" ..`           `+sssso-  +m:      `/d: .smyohm++NMs-......+dmmmh:....-+hy:`\n";
        cout<<"              :h/`  `-yyym:         -mydmNNmmmmmNNmo.......:hmmmd/.....-yNd+`\n";
        cout<<"             -m-     :ysds           +MNmmmmmmmmmmNNs.......-hmmmd/......smNd-\n";
        cout<<"             d+    `sy-.N.            mhNmmmmmmmmmmmNs.......-dmmmd-......smmN/\n";
        cout<<"            .M`    ss..:N     `       oy+Nmmmmmmmmmmmm+.......+mmmmy......-dmmN.\n";
        cout<<"            :m .s/+h...-N    +ms      :m.oNmmmmmmmmmmmd-.......hmmmm/......ommNs\n";
        cout<<"            -N sMyN:....N-   oNo`     :m..mNmmmmmmmmmmms.......ommmms......:mmNy\n";
        cout<<"            `N-.+sd.....sy    .`      +h..oNmmmmmmmmmmmm......./mmmmd......:mmM/\n";
        cout<<"             sy  oy......d/          `m/..:MmmmmmmmmmmmN:......:mmmmm......+mNy\n";
        cout<<"             `d+ /h......:d:        `ys....NmmmmmmmmmmmN/......+mmmmd......hNs`\n";
        cout<<"              .ho.N-......-ho.`    .ys-....NmmmmmmmmmmmM:......ymmmms.....oh:\n";
        cout<<"               `oymh.......-/sso++oy/-.....NmmmmmmmmmmNh......:mmmmd:..-::-\n";
        cout<<"                 `-yy-........-:::-.......-MmmmmmmmmmNm:.....:dmmmmo:::-`\n";
        cout<<"                    oh:...................+Nmmmmmmmmdy+::::-/mdhhh/.h-\n";
        cout<<"                     -yy:.................dNmmmmmmh: +s` ./  s+ .d. .m-\n";
        cout<<"                       :yy/-.............sd+oo+:--d.  sy `h: `d+ /d. :m.\n";
        cout<<"                         .oys/-........-sh`       /d. `do .m: .m: od. +d`\n";
        cout<<"                            -+syo+/::+sy+`         om. .d/ :m/ -m- +m- oh`\n";
        cout<<"                               `-:///:.             /m: .d/ -m+ :d- :d/ +h.\n";
        cout<<"                                                     -h+``y+`.ys`-h: `os`-d-\n";
        cout<<"                                                       /+  s+  :s``y-  `  `\n";
        getchar();
        system("clear");
    }

 void Ucenik::postaviJunskiRok(int moze)
    {
        junski_rok=moze;
    }

int Ucenik::izdvojiJunskiRok()
    {
        return junski_rok;
    }

double Ucenik::izracunajProsjekOcjenaOpstiUspjeh(int razred)
    {
        int i=0;
        double S=0;
        while (ocjene[razred][i+1]!=0)
            {
                i++;
                S+=apsolutnaVrijednostBroja(ocjene[razred][i]);
            }
        if (i!=0)
            return zaokruzivanjeBroja(S/i);
                else
                    return 0;
    }

double Ucenik::izracunajProsjekOcjenaPosebanUspjeh(int razred)
    {
        int i=0;
        int j=0;
        double S=0;
        while (ocjene[razred][i+1]!=0)
            {
                i++;
                if (ocjene[razred][i]<0)
                    {
                        S+=apsolutnaVrijednostBroja(ocjene[razred][i]);
                        j++;
                    }
            }
        if (j!=0)
            return zaokruzivanjeBroja(S/j);
                else
                    return 0;
    }

double Ucenik::izracunajBrojBodovaOpstiUspjeh()
    {
        double o_uspjeh1;
        o_uspjeh1=izracunajProsjekOcjenaOpstiUspjeh(1);
        double o_uspjeh2;
        o_uspjeh2=izracunajProsjekOcjenaOpstiUspjeh(2);
        double o_uspjeh3;
        o_uspjeh3=izracunajProsjekOcjenaOpstiUspjeh(3);
        double o_uspjeh4;
        o_uspjeh4=izracunajProsjekOcjenaOpstiUspjeh(4);
        if ((o_uspjeh1*o_uspjeh2*o_uspjeh3*o_uspjeh4==0) && ((o_uspjeh1!=0) || (o_uspjeh2!=0) || (o_uspjeh3!=0) || (o_uspjeh4!=0)))
            return 1;
                else
                    return o_uspjeh1*2+o_uspjeh2*2+o_uspjeh3*3+o_uspjeh4*3;
    }

double Ucenik::izracunajBrojBodovaPosebanUspjeh()
    {
        double p_uspjeh3;
        p_uspjeh3=izracunajProsjekOcjenaPosebanUspjeh(3);
        double p_uspjeh4;
        p_uspjeh4=izracunajProsjekOcjenaPosebanUspjeh(4);
        if ((p_uspjeh3*p_uspjeh4==0) && ((p_uspjeh3!=0) || (p_uspjeh4!=0)))
            return 1;
                else
                    return p_uspjeh3*2+p_uspjeh4*2;
    }

int main()
    {
            system("clear");
            Ucenik ucenik;
            vrednus();
            char c;
            c='c';
            while ((c!='D') && (c!='N'))
                {
                    cout<<"\n\nZelite li da vidite koji predmeti iz osmog i devetog razreda osnovne skole se\n";
                    cout<<"                             posebno boduju za upis?\n\n";
                    cout<<"                       DA (unesite 'D') / NE (unesite 'N')\n";
                    cout<<"                                       ";
                    cin>>c;
                    getchar();
                    system("clear");
                }
            if (c=='D')
                prilog1();
            c='D';
            int prvi;
            prvi=1;
            while (c=='D')
                {
                    if (prvi==0)
                        c='c';
                    while ((c!='D') && (c!='N'))
                        {
                            cout<<"\n\n                              Zelite li novi unos?\n\n";
                            cout<<"                       DA (unesite 'D') / NE (unesite 'N')\n";
                            cout<<"                                       ";
                            cin>>c;
                            getchar();
                            system("clear");
                        }
                    if (c=='D')
                        {
                            autorstvo=9;
                            unos(ucenik);
                            rezultati(ucenik);
                        }
                    prvi=0;
                    if (c=='N')
                        {
                           if (autorstvo==1)
                            {
                                pcela();
                            }
                            cout<<"\n                           Za kraj pritisnite ENTER!\n";
                            cout<<"                                       ";
                            getchar();
                            system("clear");
                            prvi=1;
                        }
                }
            return 0;
    }
