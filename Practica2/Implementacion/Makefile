
#-----------------------------------------MACROS-------------------------------------#
AR = ar
CXX = g++ -O3 -g -std=gnu++11 -Wall -W -fPIC
FONT = ./FUENTES
BIN = .
INC = ./FUENTES
LIB = ./FUENTES
LDFLAGS= -L$(LIB)
LDLIBS= -lAlgoritmos

#-----------------------------------EJECUTABLES A GENERAR----------------------------#
all: $(FONT)/Practica_QAP

#-----------------------------------MODULOS A COMPILAR-------------------------------#
$(FONT)/data.o : $(FONT)/data.h $(FONT)/data.cpp
	$(CXX) -c -o $(FONT)/data.o $(FONT)/data.cpp -I $(INC)

$(FONT)/solution.o : $(FONT)/data.h $(FONT)/solution.h
	$(CXX) -c -o $(FONT)/solution.o $(FONT)/solution.cpp -I $(INC)

$(FONT)/localsearch.o : $(FONT)/solution.h $(FONT)/localsearch.h $(FONT)/data.h
	$(CXX) -c -o $(FONT)/localsearch.o $(FONT)/localsearch.cpp -I $(INC)

$(FONT)/geneticalalgorithm.o : $(FONT)/solution.h $(FONT)/geneticalalgorithm.h $(FONT)/data.h $(FONT)/localsearch.h
	$(CXX) -c -o $(FONT)/geneticalalgorithm.o $(FONT)/geneticalalgorithm.cpp -I $(INC)

$(FONT)/geneticalbaldwinianalgorithm.o : $(FONT)/solution.h $(FONT)/geneticalbaldwinianalgorithm.h $(FONT)/data.h $(FONT)/localsearch.h
	$(CXX) -c -o $(FONT)/geneticalbaldwinianalgorithm.o $(FONT)/geneticalbaldwinianalgorithm.cpp -I $(INC)

$(FONT)/geneticallamarckianalgorithm.o : $(FONT)/solution.h $(FONT)/geneticallamarckianalgorithm.h $(FONT)/data.h $(FONT)/localsearch.h
	$(CXX) -c -o $(FONT)/geneticallamarckianalgorithm.o $(FONT)/geneticallamarckianalgorithm.cpp -I $(INC)

$(FONT)/ejecutable.o : $(FONT)/data.h $(FONT)/solution.h $(FONT)/localsearch.h $(FONT)/geneticalalgorithm.h $(FONT)/geneticalbaldwinianalgorithm.h $(FONT)/geneticallamarckianalgorithm.h
	$(CXX) -c -o $(FONT)/ejecutable.o $(FONT)/main.cpp -I $(INC)

#-------------------------------COMPILACION EJECUTABLES------------------------------#
$(FONT)/Practica_QAP : $(FONT)/ejecutable.o $(LIB)/libAlgoritmos.a
	$(CXX) -o $(BIN)/Practica_QAP $(FONT)/ejecutable.o $(LDFLAGS) $(LDLIBS)


#------------------------------------LIBRERIAS---------------------------------------#
$(LIB)/libAlgoritmos.a : $(FONT)/data.o $(FONT)/solution.o $(FONT)/localsearch.o $(FONT)/geneticalalgorithm.o $(FONT)/geneticalbaldwinianalgorithm.o $(FONT)/geneticallamarckianalgorithm.o
	$(AR) rvs $(FONT)/libAlgoritmos.a $(FONT)/data.o $(FONT)/solution.o $(FONT)/localsearch.o $(FONT)/geneticalalgorithm.o $(FONT)/geneticalbaldwinianalgorithm.o $(FONT)/geneticallamarckianalgorithm.o
#------------------------------------LIMPIEZA----------------------------------------#
clean:
	echo "Limpiando ..."
	-rm $(FONT)/*.o

mrproper: clean
	-rm $(BIN)/Practica_QAP
	-rm $(FONT)/*.a
