#include <Python.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]){

	Py_Initialize();
	if( !Py_IsInitialized() ){
		printf("Initialize failed\n");
		return -1;
	}
	PyRun_SimpleString("import sys");
	PyRun_SimpleString("import numpy as np");
	//PyRun_SimpleString("from tensorflow.keras.models import load_model");
	PyRun_SimpleString("sys.path.append('./')");
	//PyRun_SimpleString(model_.predict(np.array([[65, 110, 362,  65,  32]])));
	//PyRun_SimpleString("model_ = load_model('./my_model.h5')");
	//PyRun_SimpleString("model_.predict(np.array([[65, 110, 362,  65,  32]]))");

	PyObject *pName, *pModule, *pDict, *pFunc, *pArgs, *pRet;

	
	pName = PyUnicode_DecodeFSDefault("call_model_pred");
	
	pModule = PyImport_Import(pName);
	if ( !pModule ){
		return -1;
	}
	pDict = PyModule_GetDict(pModule);
	if ( !pDict ){
		return -1;
	}
	pFunc = PyDict_GetItemString(pDict, "call_model_pred");
	if ( !pFunc || !PyCallable_Check(pFunc) ){
		return -1;
	}

	//long arr1[5] = {1, 3, 5, 7, 9};
	long arr1[5] = {65, 110, 362,  65,  32};
//	long arr2[5] = {2, 4, 6, 8, 10};


	pArgs = PyTuple_New(5);  // create a tuple which has two elements


		//PyLong_AsLong for python3.x
		//PyInt_AsLong for python2.x

		PyObject* arg1 = PyLong_FromLong(arr1[0]);    // set para1 
		PyObject* arg2 = PyLong_FromLong(arr1[1]);    // set para2 
		PyObject* arg3 = PyLong_FromLong(arr1[2]);    // set para2 
		PyObject* arg4 = PyLong_FromLong(arr1[3]);    // set para2 
		PyObject* arg5 = PyLong_FromLong(arr1[4]);    // set para2 
		PyTuple_SetItem(pArgs, 0, arg1);              // set tuple 
		PyTuple_SetItem(pArgs, 1, arg2);
		PyTuple_SetItem(pArgs, 2, arg3);
		PyTuple_SetItem(pArgs, 3, arg4);
		PyTuple_SetItem(pArgs, 4, arg5);

	//	printf(" ===========> START CALL PYTHON SCRIPT %d <===========\n", i + 1);
		pRet = PyObject_CallObject(pFunc, pArgs);     // call the function
	//	printf(" ===========> CALLING FINISHED  %d <===========\n", i + 1);

		long result = PyLong_AsLong(pRet);            // get the return value by pRet
		printf(" ===========> result = %ld <===========\n", result);


	//printf(" ===========> total = %ld <===========\n", total);

	Py_DECREF(pName);
	Py_DECREF(pModule);
	Py_DECREF(pArgs);
	Py_DECREF(pRet);
	Py_DECREF(pDict);

	// close Python
	Py_Finalize();
    return 0;
}

/*
bg@bg-cgi:~/Desktop/C_python/little_demo$ make all
g++ -std=c++11 -Wall -O3 add.cpp -lpython3.5m -L/usr/include/python3.5m/ -I/usr/include/python3.5m/ -o add
bg@bg-cgi:~/Desktop/C_python/little_demo$ ./add 
 ===========> START CALL PYTHON SCRIPT 1 <===========
 ===========> CALLING FINISHED  1 <===========
 ===========> result = 3 <===========
 ===========> START CALL PYTHON SCRIPT 2 <===========
 ===========> CALLING FINISHED  2 <===========
 ===========> result = 7 <===========
 ===========> START CALL PYTHON SCRIPT 3 <===========
 ===========> CALLING FINISHED  3 <===========
 ===========> result = 11 <===========
 ===========> START CALL PYTHON SCRIPT 4 <===========
 ===========> CALLING FINISHED  4 <===========
 ===========> result = 15 <===========
 ===========> START CALL PYTHON SCRIPT 5 <===========
 ===========> CALLING FINISHED  5 <===========
 ===========> result = 19 <===========
 ===========> total = 55 <===========
*/