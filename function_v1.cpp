#include "function_v1.h"
#include "matrix_help.h"
#include "vector_help.h"
#include "math.h"

int Function(int N, double** left, double** right){

  int i, j, k;
  double tmp1, tmp2;
  double* col;

  for(i = 0; i < N; i++){

    //1) Найдем вектор отражения и запишем в первый столбец левой матрицы
    tmp1 = scalar(get_col(left, i, N),get_col(left, i, N), i + 1, N);
    tmp2 = sqrt(tmp1 + left[i][i]*left[i][i]);
      //проверка на нулевой столбец
    if(tmp2 < 1e-100){
      return -1;
    }

    left[i][i] = left[i][i] - tmp2;
    tmp1 = sqrt(tmp1 + left[i][i]*left[i][i]);

		if (tmp1 < 1e-100){
			left[i][i] = left[i][i] + tmp2;
			continue;
		}

		tmp1 = 1.0 / tmp1;
    lineXk(left, tmp1, i, i, N);


    //2) Умножим оставшиеся столбцы левой матрицы на вектор отражения
		for(k = i + 1; k < N; k++){

      tmp1 = 2.0 * scalar(get_col(left, i, N),get_col(left, k, N), i, N);

      for (j = i; j < N; j++){
				left[j][k] = left[j][k] - tmp1 * left[j][i];
      }
		}


    //3) Умножим столбцы правой матрицы на вектор отражения
		for (k = 0; k < N; k++){
      tmp1 = 2.0 * scalar(get_col(left, i, N),get_col(right, k, N), i, N);

      for (j = i; j < N; j++){
				right[j][k] = right[j][k] - tmp1 * left[j][i];
      }
		}

    
		left[i][i] = tmp2;
	}

  //4) Обратный ход в методе Гаусса
	for (k = 0; k < N; ++k){
		for (i = N - 1; i >= 0; --i){
			tmp1 = right[i][k];
			for (j = i + 1; j < N; ++j){
				tmp1 = tmp1 - left[i][j] * right[j][k];
      }
			right[i][k] = tmp1 / left[i][i];
		}
  }

	return 0;
}
