#include "SimpleBookCollection.h"
#include "SimpleGenre.h"

int main() {
	BookCollection bc;
	bc.addGenre("Fantasy");
	bc.addGenre("Action");
	bc.addGenre("Tragedy");
	bc.addGenre("Anime");
	bc.addGenre("Drama");
	bc.addGenre("Comedy");
	bc.addGenre("KIDS");
	bc.addGenre("Kids");
	bc.displayGenres();
	bc.removeGenre("Fiction");
	bc.removeGenre("Tragedy");
	bc.displayGenres();
}