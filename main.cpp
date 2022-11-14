#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iostream>
#include <list>

using namespace std;

int main() {
	//1970年時点の山手線
	const char* yamanoteLine[28] = {
		"Tokyo",
		"Kanda",
		"Akihabara",
		"Okachimachi",
		"Ueno",
		"Uguisudani",
		"Nippori",
		"Tabata",
		"Komagome",
		"Sugamo",
		"Ootuka",
		"Ikebukuro",
		"Mejiro",
		"Takadanobaba",
		"Sinookubo",
		"Sinjyuku",
		"Yoyogi",
		"Harajyuku",
		"Sibuya",
		"Ebisu",
		"Meguro",
		"Gotanda",
		"Oosaki",
		"Sinagawa",
		"Tamachi",
		"Hamamatucyou",
		"Sinbasi",
		"Yuurakucyou",
	};

	//山手線のリスト
	list<const char*> lst(28);
	auto itr = lst.begin();
	for (int i = 0; i < 28; i++) {

		*itr = yamanoteLine[i];
		itr++;
	}

	//1970年の山手線の表示
	printf("1970年の山手線\n");
	for (auto itr = lst.begin(); itr != lst.end(); ++itr) {

		cout << *itr << "\n";
		printf("  |\n");
	}

	printf("--------------------------\n");
	printf("1971年、西日暮里駅開業！\n");
	printf("--------------------------\n");

	//西日暮里駅の挿入
	for (list<const char*>::iterator itr = lst.begin(); itr != lst.end(); ++itr) {

		if (*itr == "Tabata") {
			itr = lst.insert(itr, "Nisi-Nippori");
			++itr;
		}
	}

	//2019年の山手線の表示
	printf("2019年の山手線\n");
	for (auto itr = lst.begin(); itr != lst.end(); ++itr) {

		cout << *itr << "\n";
		printf("  |\n");
	}

	printf("--------------------------------\n");
	printf("2020年、高輪ゲートウェイ駅開業！\n");
	printf("--------------------------------\n");

	//高輪ゲートウェイ駅の挿入
	for (list<const char*>::iterator itr = lst.begin(); itr != lst.end(); ++itr) {

		if (*itr == "Tamachi") {
			itr = lst.insert(itr, "Takanawa-Gateway");
			++itr;
		}
	}

	//2022年の山手線の表示
	printf("2022年の山手線\n");
	for (auto itr = lst.begin(); itr != lst.end(); ++itr) {

		cout << *itr << "\n";
		printf("  |\n");
	}


	return 0;
}