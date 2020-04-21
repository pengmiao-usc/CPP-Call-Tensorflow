#!/usr/bin/env python3.6m
from tensorflow.keras.models import load_model
import pickle
import numpy as np
import os.path
import sys
#sys.argv = ['pdm']

def call_model_pred(a1, a2, a3,a4,a5):
	r=a1+a2+a3+a4+a5
	x=np.array([a1,a2,a3,a4,a5])
	#print(x)
	model_ = load_model('./my_model.h5')
	print(x)
	print(model_)
	return r
