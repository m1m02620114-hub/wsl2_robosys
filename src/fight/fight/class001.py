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
        return self.Php <= 0

    def defeat(self):
        return self.flg >= 3

    def speed(self, field):
        field.speeds[self.Pnum] = self.Pspeed


    def hp(self, field):
        field.hps[self.Pnum] = self.Php
  

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
        self.hpsF = [0, 0]

    def battle(self):
        if self.speeds[0] >= self.speeds[1]:
            F = 0
            S = 1
        else:
            F = 1
            S = 0

        self.hpsF[S] = self.hps[S] + self.defensesP[S] - self.attacks[F]
        if self.hpsF[S] < self.hps[S]:
            self.hps[S] = self.hpsF[S]
        else:
            print("no damage")
        if self.hps[S] <= 0:
            return 0
        
        self.hpsF[F] = self.hps[F] + self.defensesP[F] - self.attacks[S]
        if self.hpsF[F] < self.hps[F]:
            self.hps[F] = self.hpsF[F]
        else:
            print("no damage")
            
        return 0