build:
	g++ main.cpp Player.cpp Team.cpp -o lanParty
run:
	./lanParty c.in d.in r.out
clean:
	rm lanParty
