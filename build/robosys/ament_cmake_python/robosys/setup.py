from setuptools import find_packages
from setuptools import setup

setup(
    name='robosys',
    version='0.0.0',
    packages=find_packages(
        include=('robosys', 'robosys.*')),
)
