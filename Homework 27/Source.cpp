#include <iostream>
#include <cstdlib>
#include <ctime>
struct movies {
	std::string title;
	int year;
	std::string genre;
	unsigned int duration;
	unsigned int price;
};
void show_movie(const movies& film) {
	std::cout << "Movie info:\nTitle: " << film.title
		<< "\nYear: " << film.year
		<< "\nGenre: " << film.genre
		<< "\nDuration: " << film.duration
		<< "\nPrice: " << film.price << "$\n";
}
movies expensive(const movies& film1, const movies& film2, const movies& film3) {
	int max = film1.price;
	max = max > film2.price ? max : film2.price;
	max = max > film3.price ? max : film3.price;

	if (max == film1.price)
		return film1;
	else
		if (max == film2.price)
			return film2;
		else
			if (max == film3.price)
				return film3;


}
void update_info(movies& film) {
	int tmp;
	std::cout << "\nВыберите, какую информацию о фильме необходимо обновить:";
	std::cout<<"\n1. Название;\n2.Год выхода;\n3.Жанр;\n4.Продолжительность;\n5.Цена за диск.;\nВвод ->";
	std::cin >> tmp;
	switch(tmp){
	case 1:
		std::cout << "Введите новое название фильма:";
		std::cin >> film.title;
		break;
	case 2:
		std::cout << "Введите новый год фильма:";
		std::cin >> film.year;
		break;
	case 3:
		std::cout << "Введите новый жанр фильма:";
		std::cin >> film.genre;
		break;
	case 4:
		std::cout << "Введите новую длительность фильма:";
		std::cin >> film.duration;
		break;
	case 5:
		std::cout << "Введите новую стоимость фильма:";
		std::cin >> film.price;
		break;
	}

}
int main() {
	setlocale(LC_ALL, "Russian");
	movies MyFilm1{
		"Potato adventures!",
		2007,
		"Thriller",
		400,
		432500
	};
	//Task 1
	std::cout << "Task 1\n";
	show_movie(MyFilm1);
	//Task 2
	movies MyFilm2{
		"o",
		2000,
		"o",
		400,
		30000
	};
	movies MyFilm3{
		"a",
		2000,
		"o",
		400,
		500000
	};
	
	std::cout << "\nTask 2.\n";
	show_movie(expensive(MyFilm1, MyFilm2, MyFilm3));
	//Task 3
	std::cout << "\n\nTask 3.\n";
	show_movie(MyFilm1);
	std::cout << std::endl;
	update_info(MyFilm1);
	std::cout << std::endl<<"Изменения:\n";
	show_movie(MyFilm1);




	return 0;
}