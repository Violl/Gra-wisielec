#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <ctime>

using namespace std;

const int CONW = 80;			//szerokosc konsoli
const int CONW_T = CONW + 1; 	//szerokosc bufora konsoli, z uwzglednieniem "/0"
const int CONH = 25;

const char WISIELEC[10][15][22] = 
{	
	//KROK_0:
	{
		"                     ",
		"                     ",
		"                     ",
		"                     ",
		"                     ",
		"                     ",
		"                     ",
		"                     ",
		"                     ",
		"                     ",
		"                     ",
		"                     ",
		"                     ",
		"                     ",
		"                     "
	},
	
	//KROK_1:
	{
		"*                    ",
		"*                    ",
		"*                    ",
		"*                    ",
		"*                    ",
		"*                    ",
		"*                    ",
		"*                    ",
		"*                    ",
		"*                    ",
		"*                    ",
		"*                    ",
		"*                    ",
		"*                    ",
		"*                    "
	},
	
	//KROK_2:
	{
		"******************   ",
		"*                    ",
		"*                    ",
		"*                    ",
		"*                    ",
		"*                    ",
		"*                    ",
		"*                    ",
		"*                    ",
		"*                    ",
		"*                    ",
		"*                    ",
		"*                    ",
		"*                    ",
		"*                    "
	},
	
	//KROK_3:
	{
		"******************   ",
		"*                *   ",
		"*                    ",
		"*                    ",
		"*                    ",
		"*                    ",
		"*                    ",
		"*                    ",
		"*                    ",
		"*                    ",
		"*                    ",
		"*                    ",
		"*                    ",
		"*                    ",
		"*                    "
	},
	
	//KROK_4:
	{
		"******************   ",
		"*                *   ",
		"*                *   ",
		"*              *   * ",
		"*               * *  ",
		"*                *   ",
		"*                    ",
		"*                    ",
		"*                    ",
		"*                    ",
		"*                    ",
		"*                    ",
		"*                    ",
		"*                    ",
		"*                    "
	},
	
	//KROK_5:
	{
		"******************   ",
		"*                *   ",
		"*                *   ",
		"*              *   * ",
		"*               * *  ",
		"*                *   ",
		"*                *   ",
		"*              * *   ",
		"*             *  *   ",
		"*                    ",
		"*                    ",
		"*                    ",
		"*                    ",
		"*                    ",
		"*                    "
	},
	
	//KROK_6:
	{
		"******************   ",
		"*                *   ",
		"*                *   ",
		"*              *   * ",
		"*               * *  ",
		"*                *   ",
		"*                *   ",
		"*              * * * ",
		"*             *  *  *",
		"*                    ",
		"*                    ",
		"*                    ",
		"*                    ",
		"*                    ",
		"*                    "
	},
	
	//KROK_7:
	{
		"******************   ",
		"*                *   ",
		"*                *   ",
		"*              *   * ",
		"*               * *  ",
		"*                *   ",
		"*                *   ",
		"*              * * * ",
		"*             *  *  *",
		"*                *   ",
		"*                *   ",
		"*               *    ",
		"*              *     ",
		"*             *      ",
		"*                    "
	},
	
	//KROK_8:
	{
		"******************   ",
		"*                *   ",
		"*                *   ",
		"*              *   * ",
		"*               * *  ",
		"*                *   ",
		"*                *   ",
		"*              * * * ",
		"*             *  *  *",
		"*                *   ",
		"*                *   ",
		"*               * *  ",
		"*              *   * ",
		"*             *     *",
		"*                    "
	},
	
	//WYGRANA
	{
		"                     ",
		"                     ",
		"          *          ",
		"        *   *        ",
		"         * *         ",
		"          *          ",
		"       *  *  *       ",
		"        * * *        ",
		"          *          ",
		"          *          ",
		"          *          ",
		"         * *         ",
		"        *   *        ",
		"       *     *       ",
		"                     "
	}
};

const char SLOWNIK[100][11] =
{
	"ananas",
	"antarktyda",
	"anatomia",
	"altana",
	"atlas",
	"banan",
	"bateria",
	"baklazan",
	"batuta",
	"bilet",
	"centymetr",
	"centaur",
	"cecha",
	"celebryta",
	"calka",
	"decymetr",
	"denaturat",
	"demolka",
	"decyzja",
	"dramat",
	"etiopia",
	"element",
	"egzamin",
	"energia",
	"enzym",
	"fortepian",
	"forteca",
	"fasada",
	"fraza",
	"fabula",
	"godzina",
	"geografia",
	"geometria",
	"gatunek",
	"gazela",
	"haslo",
	"haczyk",
	"habitat",
	"herbata",
	"hamburger",
	"iteracja",
	"iberia",
	"ideologia",
	"idealista",
	"igielnica",
	"jadalnia",
	"jadlospis",
	"jajecznica",
	"jalowiec",
	"jamnik",
	"kangur",
	"kobalt",
	"kucharz",
	"kaczka",
	"kadzidelko",
	"lemur",
	"lampard",
	"latawiec",
	"labirynt",
	"lakiernik",
	"macedonia",
	"mechanik",
	"maczuga",
	"magnetofon",
	"magister",
	"narrator",
	"nawigacja",
	"naczynie",
	"nadajnik",
	"napiecie",
	"obcinak",
	"obiad",
	"obiekt",
	"odlamek",
	"obrada",
	"paciorek",
	"pajeczak",
	"pajac",
	"palma",
	"palisada",
	"rabus",
	"rabarbar",
	"radar",
	"radio",
	"rakieta",
	"schowek",
	"sacharoza",
	"sajgonka",
	"salon",
	"salatka",
	"taras",
	"taran",
	"teatr",
	"teoria",
	"tapioka",
	"wawrzyniec",
	"wiadro",
	"wandal",
	"wisielec",
	"zabytek"
};

void clrBuf(char conBuf[CONH][CONW_T]);
void prntBuf(char conBuf[CONH][CONW_T], int start, int stop);
void rysujKreski(char conBuf[CONH][CONW_T], int dlugoscSlowa);
void rysujKrok(char conBuf[CONH][CONW_T], int krok);
void rysujPodajLitere(char conBuf[CONH][CONW_T], int& bledy, int dlugoscSlowa, char slowo[11], bool& wygrana, int& wystapienia);
void obsluzPodajLitere(char conBuf[CONH][CONW_T], int& bledy, int dlugoscSlowa, char slowo[11], bool& wygrana, int& wystapienia);

int main()
{
	srand(time(NULL));
	
	char conBuf[CONH][CONW_T];
	clrBuf(conBuf);
	
	int gry = 0;
	int wynik = 0;
	bool nastepnaTura;
	
	do 
	{
		int wylosowanyIndeks = rand() % 100;
		int dlugoscSlowa = strlen(SLOWNIK[wylosowanyIndeks]);
		char slowo[11] = {0};
		strncpy(slowo, SLOWNIK[wylosowanyIndeks], dlugoscSlowa);
	
		nastepnaTura = false;
		int bledy = 0;
		bool wygrana = false;
		int wystapienia = 0;
		
		while (bledy < 8 && !wygrana)
		{
			rysujKrok(conBuf, bledy);
			rysujKreski(conBuf, dlugoscSlowa);	
			rysujPodajLitere(conBuf, bledy, dlugoscSlowa, slowo, wygrana, wystapienia);					
		}	
	
		if (bledy == 8)
		{
			clrBuf(conBuf);
			rysujKrok(conBuf, 8);
			strncpy(conBuf[19]+27, "Niestety, przegrana!!! :(((", 27);
			wynik--;
			prntBuf(conBuf, 0, CONH-4);
		}
		else if (wygrana)
		{
			clrBuf(conBuf);
			rysujKrok(conBuf, 9);
			strncpy(conBuf[19]+27, "Gratulacje, wygrana!!! :)))", 27);
			wynik++;
			prntBuf(conBuf, 0, CONH-4);
		}
		
		char decyzja;
		cout << "Twoja obecna liczba punktow to : "<<wynik<<endl;
		cout << "Sprobowac jeszcze raz? [T]ak/[N]ie: ";
		cin >> decyzja;
		
		switch (decyzja)
		{
			case 'T': nastepnaTura = true; clrBuf(conBuf); break;
			case 't': nastepnaTura = true; clrBuf(conBuf); break;
			case 'N': nastepnaTura = false; break;
			case 'n': nastepnaTura = false; break;
			default: exit(0); break;
		}
	}
	while (nastepnaTura);
		
	return 0;
}

//czyszczenie bufora konsoli
void clrBuf(char conBuf[CONH][CONW_T])
{
	for (int i = 0; i < CONH; i++)
		for (int j = 0; j < CONW; j++)
		{
			conBuf[i][j] = 32; //wszystkie komorki poza ostatnimi w wierszu wypelniane sa spacja
			conBuf[i][CONW_T - 1] = 0; //ostatnie komorki w wierszu wypelniane sa NULLem
		}
}

//wyswietlanie zawartosci bufora
void prntBuf(char conBuf[CONH][CONW_T], int start, int stop)
{
	system("cls");
	for (int row = start; row < stop; row++)
	{
			cout << conBuf[row]; //dzieki znakowi NULL na koncu wiersza mozna cout'owac cale wiersze
	}
}

//rysowanie kresek
void rysujKreski(char conBuf[CONH][CONW_T], int dlugoscSlowa)
{
	int start_x = (81 - (2 * dlugoscSlowa)) / 2;
	
	for (int i = 0; i < dlugoscSlowa; i++)
		conBuf[19][start_x + 2*i] = '_';
		
	prntBuf(conBuf, 0, CONH - 3);	
}

//rysowanie kolejnego kroku wisielca
void rysujKrok(char conBuf[CONH][CONW_T], int krok)
{
	int start_y = 3;
	int start_x = 29;
		
	for (int i = 0; i < 15; i++)
		strncpy(conBuf[i+start_y]+start_x, WISIELEC[krok][i], 21);	
		
	if (krok == 9)
		conBuf[6][39] = 2;
		
	prntBuf(conBuf, 0, CONH - 3);
}


void rysujPodajLitere(char conBuf[CONH][CONW_T], int& bledy, int dlugoscSlowa, char slowo[11], bool& wygrana, int& wystapienia)
{
	strncpy(conBuf[CONH - 4], "Podaj nastepna litere: ", 23);
	prntBuf(conBuf, 0, CONH - 3);
	obsluzPodajLitere(conBuf, bledy, dlugoscSlowa, slowo, wygrana, wystapienia);	
}


void obsluzPodajLitere(char conBuf[CONH][CONW_T], int& bledy, int dlugoscSlowa, char slowo[11], bool& wygrana, int& wystapienia)
{
	char litera;
	cin >> litera;
	
	if (litera <= 90 && litera >= 65)
		litera += 32;
		
	bool istnienia = false;
	
	for (int i = 0; i < dlugoscSlowa; i++)
		if (slowo[i] == litera)
		{
			istnienia = true;
			wystapienia++;
			conBuf[18][(81 - (2 * dlugoscSlowa)) / 2 + 2*i] = litera;			
		}
			
	if (!istnienia)
	{				
		strncpy(conBuf[3]+3, "Uzyte litery: ", 14);	
		conBuf[5][3+bledy*3] = litera;
		conBuf[5][4+bledy*3] = ',';
		conBuf[5][5+bledy*3] = 32;
		bledy++;	
	}
	
	if (wystapienia == dlugoscSlowa)
		wygrana = true;
}
