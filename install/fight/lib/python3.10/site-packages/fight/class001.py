class Player:
    def __init__(self, Pname, Pnum, monsters, Php, Pspeed, Pattack, Pdefense)
        self.Pname = Pname
        self.Pnum = Pnum
        self.monsters = monsters
        self.Php = Php
        self.Pspeed = Pspeed
        self.Pattack = Pattack
        self.Pdefense = Pdefense
        self.flg = 0

    def dead(self):
        return Php < = 0
    
    def speed(self):
        field.speeds[Pnum] = self.Pspeed

    def hp(self, field):
        field.hps[Pnum] = self.Php

    def attack(self, field):
        field.attacksP[self.Pnum] = field.attacks[self.Pnum]
        field.attacks[self.Pnum] = self.Pattack

    def defense(self, field):
        field.defensesP[self.Pnum] = field.defenses[self.Pnum]
        field.defenses[self.Pnum] = self.Pdefense

class Field:
    def __init__(self, attacks, attacksP, defenses, defensesP, speeds, hps):
        self.attacks = attacks
        self.attacksP = attacksP
        self.defenses = defenses
        self.defensesP = defensesP
        self.speeds
        self.hps

    def battle(self, P1, P2):
        if self.