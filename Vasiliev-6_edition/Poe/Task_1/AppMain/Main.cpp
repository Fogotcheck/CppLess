#include "Main.h"
using namespace std;
#include <map>
#include <set>

class Book {
    private:
	std::map<std::string, std::string> BookInfo;

    public:
	Book(const std::map<std::string, std::string> &NewBook)
	{
		if (NewBook.find("isbn") == NewBook.end()) {
			throw std::invalid_argument("Error: missing ISBN");
		}
		BookInfo = NewBook;
	}

	void ShowInfo() const
	{
		for (const auto &Item : BookInfo) {
			std::cout << Item.first << ": " << Item.second
				  << std::endl;
		}
	}

	std::string getISBN() const
	{
		return BookInfo.at("isbn");
	}

	// Оператор сравнения для std::set
	bool operator<(const Book &other) const
	{
		return getISBN() < other.getISBN();
	}
};

class Library {
    private:
	std::set<Book> BooksLib;

    public:
	void AddNewBook(const Book &NewBook)
	{
		auto result = BooksLib.insert(NewBook);
		if (result.second) {
			std::cout << "Book added: " << NewBook.getISBN()
				  << std::endl;
		} else {
			std::cout << "Book with ISBN " << NewBook.getISBN()
				  << " already exists." << std::endl;
		}
	}
	void Show(void)
	{
		std::cout << "Lib::";
		for (const auto &ItemBook : BooksLib) {
			std::cout << std::endl;
			ItemBook.ShowInfo();
		}
		std::cout << std::endl;
	}

	void RemoveBook(const std::string &isbn)
	{
		auto it = BooksLib.find(
			Book({ { "isbn",
				 isbn } })); // Используем временный объект Book
		if (it != BooksLib.end()) {
			BooksLib.erase(it);
			std::cout << "Book removed: " << isbn << std::endl;
		} else {
			std::cout << "Book not found: " << isbn << std::endl;
		}
	}

	void FindBook(const std::string &isbn) const
	{
		auto it = BooksLib.find(
			Book({ { "isbn",
				 isbn } })); // Используем временный объект Book
		if (it != BooksLib.end()) {
			it->ShowInfo();
		} else {
			std::cout << "Book not found: " << isbn << std::endl;
		}
	}
};

int main()
{
	try {
		Book JFogotcheckBook({ { "isbn", "001" },
				       { "author", "J.Fogotcheck" },
				       { "title", "Hello" },
				       { "Year", "1920" } });
		Book MataBook({ { "isbn", "002" },
				{ "author", "J.Mata" },
				{ "title", "Hello world" },
				{ "Year", "1921" } });
		Book JFogotBook({ { "isbn", "001" },
				  { "author", "J.Fogotcheck" },
				  { "title", "Hello" },
				  { "Year", "1920" } });
		JFogotcheckBook.ShowInfo();
		std::cout << std::endl;
		MataBook.ShowInfo();
		std::cout << std::endl;

		Library CityLib;
		CityLib.AddNewBook(MataBook);
		CityLib.AddNewBook(JFogotcheckBook);
		CityLib.AddNewBook(JFogotBook);

		CityLib.Show();

		CityLib.FindBook("001");
		CityLib.RemoveBook("002");
		CityLib.FindBook("002");

		CityLib.Show();

	} catch (const std::exception &e) {
		std::cerr << e.what() << '\n';
	}

	return 0;
}
