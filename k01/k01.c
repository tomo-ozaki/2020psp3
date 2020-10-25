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

#define DEBUG
//  #define MAX_CITY    1741
#define MAX_CITY    21


void PrintCity(City city)
{
    printf("%d, %s, %s, %d, %d, %d\n", city.id, city.pref, city.name, city.population, city.m_population, city.f_population);
}

void PrintArray(City city[], int size)
{
    int i;

    for (i=0; i<size; i++) {
        PrintCity(city[i]);
    }
}

int LoadData(City arrayCity[])
{
    FILE* fp;
    char buf[256];

    fp = fopen("nagasaki.csv","r");
    if(fp==NULL){
        fputs("File open error\n",stderr);
        return -1;
    }

    int cn = 0; // 市の数
    while(fgets(buf,sizeof(buf),fp) != NULL){
        sscanf(buf,"%d,%[^,],%[^,],%d,%d,%d", &(arrayCity[cn].id), arrayCity[cn].pref, arrayCity[cn].name, &(arrayCity[cn].population), &(arrayCity[cn].m_population), &(arrayCity[cn].f_population));
#ifdef DEBUG
        PrintCity(arrayCity[cn]);
#endif
        cn++;
    }

    if(fclose(fp) == EOF){
        fputs("file close error\n",stderr);
        return -1;
    }

    return cn;
}



int LinearSearch(int key, City arrayCity[], int size)
{
    int pos;
    for(pos = 0 ; pos < size ; pos++){
        if( key == arrayCity[pos].id ){
            return pos;
            break;
        }
    }
    return -1;

}

int BinarySearch(int key, City arrayCity[], int left, int right)
{
    int pos;
    int result;

    result = -1;
    while(left <= right){
        pos = left + (right - left) / 2;
        if(key == arrayCity[pos].id){
            result = pos;
            break;
        }
        else if(key > arrayCity[pos].id){
            left = pos + 1;
        }
        else{
            right = pos - 1;
        }
    }
    return result;
    


}



int main(void)
{
    int key;
    int result;

    //  事前準備。データの読み込み、配列の作成
    City* arrayCity;
    int cn;
    arrayCity = (City*)malloc(sizeof(City) * MAX_CITY);
    cn = LoadData(arrayCity);
    if (cn == -1) {
        exit(EXIT_FAILURE);
    }

    //  IDで検索
    printf("\n===== linear search =====\n");
    printf("City ID?");
    scanf("%d", &key);
    result = LinearSearch(key, arrayCity, MAX_CITY);
    if (result != -1) {
        PrintCity(arrayCity[result]);
    } else {
        printf("city was not found\n");
    }

    printf("\n===== binary search =====\n");
    printf("City ID?");
    scanf("%d", &key);
    result = BinarySearch(key, arrayCity, 0, MAX_CITY - 1);
    if (result != -1) {
        PrintCity(arrayCity[result]);
    } else {
        printf("city was not found\n");
    }

    //  後処理
    free(arrayCity);

    return 0;
}