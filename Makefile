.all:
	echo "Compiling..."
	g++ -Ilibs/include/ src/main.cpp -o ragnar-portal

run: .all
	echo "Running..."
	./ragnar-portal

