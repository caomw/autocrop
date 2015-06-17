#!/usr/bin/env python2

import os

import cv2 as cv
import numpy as np

from Classifier import *
from FeatMat import *

def main():
    # Initialise classifier
    classifier = Classifier()

    # Go to script's directory
    os.chdir(os.path.dirname(os.path.realpath(__file__)))

    # Evaluates accuracy of classifier
    def evaluate_dir(path):
        featMat = FeatMat()
        file_to_feat = featMat.getFeatures(path)
        print('Loaded %d features for %s' % (len(file_to_feat), path))

        classifs = featMat.getClasses(path)

        errs = []
        i = 0
        for fname, fclassifs in classifs.iteritems():
            tru_cls = np.average(fclassifs)
            est_cls = classifier.predictFeats(file_to_feat['%s/%s' % (path, fname)])
            errs.append(tru_cls - est_cls)
            if tru_cls != est_cls:
                #print('%f %d' % (tru_cls, est_cls))
                i += 1

        err = np.linalg.norm(errs, 1) # L2-error norm
        print('%.3f L1-error' % (err / len(errs)))

    evaluate_dir('../datasets/Michael')
    evaluate_dir('../datasets/Wookie')

if __name__ == '__main__':
    main()

