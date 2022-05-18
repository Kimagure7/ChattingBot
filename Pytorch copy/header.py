'''
Author: MomoTori
Date: 2022-05-14 17:03:19
LastEditors: MomoTori
LastEditTime: 2022-05-18 10:03:58
FilePath: \Pytorch copy\header.py
Description: 
Copyright (c) 2022 by MomoTori, All Rights Reserved. 
'''
from __future__ import absolute_import, division, print_function, unicode_literals

import torch
from torch.jit import script, trace
import torch.nn as nn
from torch import optim
import torch.nn.functional as F
import csv
import random
import re
import os
import unicodedata
import codecs
from io import open
import itertools
import math
import jieba


# Configure training/optimization
clip = 50.0
teacher_forcing_ratio = 1.0
learning_rate = 0.0001
decoder_learning_ratio = 5.0
n_iteration = 4000
print_every = 1
save_every = 500

# Configure models
model_name = 'cb_model'
attn_model = 'dot'
#attn_model = 'general'
#attn_model = 'concat'
hidden_size = 500
encoder_n_layers = 2
decoder_n_layers = 2
dropout = 0.1
batch_size = 64