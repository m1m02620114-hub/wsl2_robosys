from setuptools import find_packages
from setuptools import setup

setup(
    name='rsysmsg',
    version='0.0.0',
    packages=find_packages(
        include=('rsysmsg', 'rsysmsg.*')),
)
