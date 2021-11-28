#include <stdio.h>
//Modificar el arreglo con las calificaciones mas altas
//Hacer un nuevo array, quitando repetidos. comparando el nuevo elemento con los antes agregados.
int main() {
	//Varaibles
	int i, ii = 0;
	int numAlm;
	scanf_s("%i", &numAlm);

	const int numAlmMax = 2002;
	int aAlmC[numAlmMax];
	float aCalifAlm[numAlmMax];

	if (numAlm == 1) {
		int nC;
		float calif;
		scanf_s("%i", &nC);
		scanf_s("%f", &calif);
		printf("%i\n%i %f", numAlm, nC, calif);
		return 0;
	}
	if (numAlm == 0) {
		printf("%i", numAlm);
		return 0;
	}

	//Escaneo de Datos
	for (i = 0; i < numAlm; i++) {
		scanf_s("%i", &aAlmC[i]);
		scanf_s("%f", &aCalifAlm[i]);
	}

	//Elimina califi inferiores y deja las calif maximas de cada alumno en todos los registros
	int iii = 0;
	while (numAlm > iii)
	{
		for (i = 0; i < numAlm; i++)
		{
			if (aAlmC[ii] == aAlmC[i])
			{
				if (aCalifAlm[ii] < aCalifAlm[i])
				{
					aCalifAlm[ii] = aCalifAlm[i];
				} else aCalifAlm[i] = aCalifAlm[ii];
			}
		}
		iii++;
		ii++;
	}

	//Nuevo array sin registros repetidos
	i = 0;
	int nNumAlm = numAlm;
	while (numAlm > i)
	{
		for (ii = i + 1; ii <= nNumAlm; ii++)
		{
			if (aAlmC[i] == aAlmC[ii])
			{
				//aAlmC[ii] == aAlmC[ii + 1];
				for (int c = ii; c < numAlm; c++)
				{
					aAlmC[c] = aAlmC[c + 1];
					aCalifAlm[c] = aCalifAlm[c + 1];
				}
				nNumAlm--;
				ii = i;
			}
		}
		i++;
	}


	//Acomodar por numero de cuenta menor a mayor
	int limbo1, limbo2;
	float limboc1, limboc2;
	//iii = 0;
	//ii = 0;
	i = 0;
	while (numAlm > i)
	{
		for (ii = i + 1; ii < nNumAlm; ii = ii + 1)
		{
			if (aAlmC[i] > aAlmC[ii])
			{
				limbo1 = aAlmC[i];
				limbo2 = aAlmC[ii];
				limboc1 = aCalifAlm[i];
				limboc2 = aCalifAlm[ii];
				aAlmC[i] = limbo2;
				aAlmC[ii] = limbo1;
				aCalifAlm[i] = limboc2;
				aCalifAlm[ii] = limboc1;
				//limboi = ii;
			}
		}
		i++;
	}

	//Respuesta
	printf("%i\n", nNumAlm);
	for (i = 0; i < nNumAlm; i++)
	{
		if (i != nNumAlm - 1)
		{
			printf("%i %f\n", aAlmC[i], aCalifAlm[i]);
		} else
		printf("%i %f", aAlmC[i], aCalifAlm[i]);
	}
	return 0;



	//atacar los prblemas en la lectura de datos?
	// atcar el problema despues de la lectura?
	//Quitar repetidos maybe un nuevo array?
	//Acomodar alumnos de menor a mayor por numero de cuenta;
	//Calif maxima (implementar en lectura de datos?)

}