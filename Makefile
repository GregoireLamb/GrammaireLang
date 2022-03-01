#Makefile générique créé par Arhur TONDEREAU
#Outils
CXX=g++
LD=g++
RM=rm
ECHO=echo

#Options
CXXFLAGS=-g -ansi -pedantic -Wall -std=c++11
LDFLAGS=
RMFLAGS=-rf

#Fichiers
HEAD=$(wildcard *.h)
SRC=$(wildcard *.cpp)
OBJ=$(SRC:.cpp=.o)
LIBS=

#Cibles speciales
EXE=calculator
RUN=execute
CLEAN=clean
.PHONY: $(CLEAN) $(RUN)

#Cibles
$(EXE): $(OBJ)
	@$(ECHO) Edition des liens
	@$(LD) $(LDFLAGS) $^ -o $@ $(LIBS)
	@$(RM) $(RMFLAGS) $(OBJ)


$(RUN): $(EXE)
	@$(ECHO) Execution de $^
	@./$(EXE)

$(CLEAN):
	@$(RM) $(RMFLAGS) $(EXE) $(OBJ)

#Dependances complementaires

#Regles d'inference
%.o: %.cpp
	@$(ECHO) Compilation de $<
	@$(CXX) $(CXXFLAGS) -c $< -o $@
