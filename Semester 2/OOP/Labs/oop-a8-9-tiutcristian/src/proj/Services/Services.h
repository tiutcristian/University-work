#pragma once
#include <string>
#include "../Repository/Repository.h"
#include "../Domain/DomainValidator.h"
#include "../Basket/FileBasket.h"

using namespace std;

class Services
{
private:
	Repository& repo;
	DomainValidator validator;

public:
	// Default constructor for a Service.
	Services(Repository& repo) : repo{ repo } {}

	// Copy constructor for a Service.
	Services(const Services& s) : repo{ s.repo } {}

	void initializeServ();

	// Adds a new element to the repository.
	void add(char size, string color, double price, int quantity, string photo);
	
	// Removes an element from the repository.
	void remove(char size, string color);
	
	// Updates an element from the repository.
	void update(char size, string color, double newPrice, int newQuantity, string newPhoto);

	// Decrement the quantity of an element from the repository.
	void decrementQuantity(char size, string color) { this->repo.decrementQuantity(size, color); }
	
	// Returns the elements from the repository as a string.
	string getElementsAsString();

	// Returns the elements from the repository in a vector.
	vector<Coat> getElements() { return this->repo.getElements(); }

	// Returns the repository filtered by size.
	Repository filterBySize(char size) { return this->repo.filterBySize(size); }

	int getQuantityBySize(char size) { return this->repo.getQuantityBySize(size); }
	
	// Tests
	static void testService();
};