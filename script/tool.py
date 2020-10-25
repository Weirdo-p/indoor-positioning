# his script is used to rename data files
# collected by whu_gnss app
# author ZHUOXU WHU
import os

# first, load folders
FolderPath = "/home/weirdo/Documents/indoor-positioning/"
folders = os.listdir(FolderPath)
folders.sort()
# go through folders in order to extract wifi data file and point number
targetPath = "/home/weirdo/Documents/indoor-positioning-new/"
for folder in folders:
    files = os.listdir(FolderPath + folder)
    files.sort()
    # file[0] is the point number, file[5] is wifi data
    # point num is between _ and .
    pointNum = str(files[0][files[0].find('_') + 1 : files[0].find('.')])
    # copy and rename data files
    os.system("cp " + FolderPath + folder + '/' + files[5] + " " + targetPath + pointNum + ".txt")