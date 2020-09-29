#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 市町村別データを入れる構造体
typedef struct {
    int id; //  市町村ID
    char pref[13];  // 県名
    char name[19];  // 市町村名
    int population; // 人口
    int m_population;   // 男性人口
    int f_population;   // 女性人口
} City;

//  リストを作る構造体
typedef struct node_data {
    City city;
    struct node_data* pNext;
} Node;

#define DEBUG
//#define CHALLENGE1
//#define CHALLENGE2

#define SUCCESS 1
#define ERROR   0
#define MAX_CITY    21

void PrintCity(City city)
{
    printf("%d, %s, %s, %d, %d, %d\n", city.id, city.pref, city.name, city.population, city.m_population, city.f_population);
}

void ReleaseList(Node* pTop)
{
    Node* pNode;
    Node* pTemp;
    int cn = 0;

    pNode = pTop;
    
    while(pNode != NULL) {
        pTemp = pNode;
        pNode = pNode->pNext;
        free(pTemp);
        cn++;
    }

#ifdef DEBUG
    printf("free list. items = %d\n", cn);
#endif
}

void PrintList(Node* pTop)
{
    Node* pNode;
    pNode = pTop;
    int cn = 0;
    
    printf("===== Start Printing =====\n");

    while(pNode != NULL) {
        PrintCity(pNode->city);
        pNode = pNode->pNext;
        cn++;
    }

#ifdef DEBUG
    printf("print list. items = %d\n", cn);
#endif

   printf("===== Print End =====\n");

}

Node* InsertNewNode(City newCity, Node* pNext)
{
    //  ここを実装する

}

#ifdef CHALLENGE1
int DeleteNodeAt(Node** ppNode, int cn)
{
    //  チャレンジ問題1
    //  ここを実装する

}
#endif

#ifdef CHALLENGE2
int SearchCityByName(Node* pList, char* cityName, City* pCity)
{
    //  チャレンジ問題2
    //  ここを実装する

}
#endif

int SearchCityByID(Node* pList, int ID, City* pCity)
{
    // ここを実装する

}

int main(void)
{
    char buf[256];
    FILE* fp;
    int key;

    fp = fopen("nagasaki.csv","r");
    if(fp==NULL){
        fputs("File open error\n",stderr);
        exit(EXIT_FAILURE);
    }


    Node* pTop = NULL;  //  リストの先頭
    City city;  //　市町村別データ
    int cn = 0; // 市の数
    while(fgets(buf,sizeof(buf),fp) != NULL){
        // 1市町村毎にデータを読み込み、City型構造体にデータの格納
        sscanf(buf,"%d,%[^,],%[^,],%d,%d,%d", &(city.id), city.pref, city.name, &(city.population), &(city.m_population), &(city.f_population));
#ifdef DEBUG
        // 読み込んだ市町村データを出力する
        PrintCity(city);
#endif
        //  読み込んだ市町村データをリストの先頭に挿入し
        //  その先頭をpTopに入れる
        pTop = InsertNewNode(city, pTop);
    
        cn++;
    }

    //  作成したリストを出力する
    PrintList(pTop);

    // IDで特定の市町村を探す
    printf("City ID?");
    scanf("%d", &key);
    cn = SearchCityByID(pTop, key, &city);
    if (cn != -1) {
        printf("the city was found at %d\n", cn);
        PrintCity(city);
    } else {
        printf("sorry, the city was not found\n");
    }

#ifdef CHALLENGE1
    //  市町村名で特定の市町村を探す
    char name[32];
    printf("City Name?");
    scanf("%s", name);
    cn = SearchCityByName(pTop, name, &city);
    if (cn != -1) {
        printf("the city was found at %d\n", cn);
        PrintCity(city);
    } else {
        printf("sorry, the city was not found\n");
    }
#endif

#ifdef CHALLENGE2
    // 特定の場所のノードを削除する
    // cnは直前の検索結果
    DeleteNodeAt(&pTop, cn);
    PrintList(pTop);
#endif

    ReleaseList(pTop);

    if(fclose(fp) == EOF){
        fputs("file close error\n",stderr);
        exit(EXIT_FAILURE);
    }
}