extern THStack* IntStackColl_2b2n[];
extern THStack* ExtStackColl_2b2n[];
extern THStack* RadStackColl_2b2n[];
extern THStack* SigStackColl_2b2n[];

Double_t TotalMC_2b2n(Int_t HistNum, Double_t x, const Double_t *par);

Double_t TotalMC_2b2n_SeOld(Double_t x, const Double_t *par){return TotalMC_2b2n(0,x,par);}
Double_t TotalMC_2b2n_SeNew(Double_t x, const Double_t *par){return TotalMC_2b2n(1,x,par);}

Double_t TotalMC_2b2n(Int_t HistNum, Double_t x, const Double_t *par){

  // Initialise bin and TotalMC for bin
  Int_t bin = ((TH1D*)StackColl_2b2n[HistNum]->GetStack()->Last())->FindBin(x);
  double TotalMC = 0;

  // Bi214 & Pb214 - SeNew
  TotalMC += par[0]* ((TH1D*)IntStackColl_2b2n[HistNum]->GetStack()->At(0))->GetBinContent(bin);
  TotalMC += par[0]*(((TH1D*)IntStackColl_2b2n[HistNum]->GetStack()->At(3))->GetBinContent(bin)-
		     ((TH1D*)IntStackColl_2b2n[HistNum]->GetStack()->At(2))->GetBinContent(bin));

  // Bi214 & Pb214 - SeOld
  TotalMC += par[1]*(((TH1D*)IntStackColl_2b2n[HistNum]->GetStack()->At(1))->GetBinContent(bin)-
		     ((TH1D*)IntStackColl_2b2n[HistNum]->GetStack()->At(0))->GetBinContent(bin));
  TotalMC += par[1]*(((TH1D*)IntStackColl_2b2n[HistNum]->GetStack()->At(4))->GetBinContent(bin)-
		     ((TH1D*)IntStackColl_2b2n[HistNum]->GetStack()->At(3))->GetBinContent(bin));

  // Bi214 & Pb214 - Mylar
  TotalMC += par[2]*(((TH1D*)IntStackColl_2b2n[HistNum]->GetStack()->At(2))->GetBinContent(bin)-
		     ((TH1D*)IntStackColl_2b2n[HistNum]->GetStack()->At(1))->GetBinContent(bin));
  TotalMC += par[2]*(((TH1D*)IntStackColl_2b2n[HistNum]->GetStack()->At(5))->GetBinContent(bin)-
		     ((TH1D*)IntStackColl_2b2n[HistNum]->GetStack()->At(4))->GetBinContent(bin));

  // Bi214 & Pb214 - SWire P1
  TotalMC += par[3]*par[4]*((TH1D*)RadStackColl_2b2n[HistNum]->GetStack()->At(0))->GetBinContent(bin);
  TotalMC += par[3]*par[4]*(((TH1D*)RadStackColl_2b2n[HistNum]->GetStack()->At(2))->GetBinContent(bin)-
			    ((TH1D*)RadStackColl_2b2n[HistNum]->GetStack()->At(1))->GetBinContent(bin));

  // Bi214 & Pb214 - SFoil In P1
  TotalMC += par[3]*par[5]*(((TH1D*)RadStackColl_2b2n[HistNum]->GetStack()->At(8))->GetBinContent(bin)-
			    ((TH1D*)RadStackColl_2b2n[HistNum]->GetStack()->At(7))->GetBinContent(bin));
  TotalMC += par[3]*par[5]*(((TH1D*)RadStackColl_2b2n[HistNum]->GetStack()->At(12))->GetBinContent(bin)-
			    ((TH1D*)RadStackColl_2b2n[HistNum]->GetStack()->At(11))->GetBinContent(bin));

  // Bi214 & Pb214 - SFoil Out P1
  TotalMC += par[3]*par[6]*(((TH1D*)RadStackColl_2b2n[HistNum]->GetStack()->At(10))->GetBinContent(bin)-
			    ((TH1D*)RadStackColl_2b2n[HistNum]->GetStack()->At(9))->GetBinContent(bin));
  TotalMC += par[3]*par[6]*(((TH1D*)RadStackColl_2b2n[HistNum]->GetStack()->At(14))->GetBinContent(bin)-
			    ((TH1D*)RadStackColl_2b2n[HistNum]->GetStack()->At(13))->GetBinContent(bin));

  // Bi214 & Pb214 - SWire P2
  TotalMC += par[4]*(((TH1D*)RadStackColl_2b2n[HistNum]->GetStack()->At(1))->GetBinContent(bin)-
		     ((TH1D*)RadStackColl_2b2n[HistNum]->GetStack()->At(0))->GetBinContent(bin));
  TotalMC += par[4]*(((TH1D*)RadStackColl_2b2n[HistNum]->GetStack()->At(3))->GetBinContent(bin)-
		     ((TH1D*)RadStackColl_2b2n[HistNum]->GetStack()->At(2))->GetBinContent(bin));

  // Bi214 & Pb214 - SFoil In P2
  TotalMC += par[5]*(((TH1D*)RadStackColl_2b2n[HistNum]->GetStack()->At(9))->GetBinContent(bin)-
		     ((TH1D*)RadStackColl_2b2n[HistNum]->GetStack()->At(8))->GetBinContent(bin));
  TotalMC += par[5]*(((TH1D*)RadStackColl_2b2n[HistNum]->GetStack()->At(13))->GetBinContent(bin)-
		     ((TH1D*)RadStackColl_2b2n[HistNum]->GetStack()->At(12))->GetBinContent(bin));

  // Bi214 & Pb214 - SFoil Out P2
  TotalMC += par[6]*(((TH1D*)RadStackColl_2b2n[HistNum]->GetStack()->At(11))->GetBinContent(bin)-
		     ((TH1D*)RadStackColl_2b2n[HistNum]->GetStack()->At(10))->GetBinContent(bin));
  TotalMC += par[6]*(((TH1D*)RadStackColl_2b2n[HistNum]->GetStack()->At(15))->GetBinContent(bin)-
		     ((TH1D*)RadStackColl_2b2n[HistNum]->GetStack()->At(14))->GetBinContent(bin));

  // Tl208 - SWire P1
  TotalMC += par[7]*(((TH1D*)RadStackColl_2b2n[HistNum]->GetStack()->At(6))->GetBinContent(bin)-
		     ((TH1D*)RadStackColl_2b2n[HistNum]->GetStack()->At(5))->GetBinContent(bin));

  // Tl208 - SWire P2
  TotalMC += par[8]*(((TH1D*)RadStackColl_2b2n[HistNum]->GetStack()->At(7))->GetBinContent(bin)-
		     ((TH1D*)RadStackColl_2b2n[HistNum]->GetStack()->At(6))->GetBinContent(bin));

  // Tl208 - SeNew
  TotalMC += par[9]*(((TH1D*)IntStackColl_2b2n[HistNum]->GetStack()->At(6))->GetBinContent(bin)-
		     ((TH1D*)IntStackColl_2b2n[HistNum]->GetStack()->At(5))->GetBinContent(bin));
  TotalMC += par[9]*(((TH1D*)IntStackColl_2b2n[HistNum]->GetStack()->At(8))->GetBinContent(bin)-
		     ((TH1D*)IntStackColl_2b2n[HistNum]->GetStack()->At(7))->GetBinContent(bin));
  TotalMC += par[9]*(((TH1D*)IntStackColl_2b2n[HistNum]->GetStack()->At(10))->GetBinContent(bin)-
		     ((TH1D*)IntStackColl_2b2n[HistNum]->GetStack()->At(9))->GetBinContent(bin));

  // Tl208 - SeOld
  TotalMC += par[10]*(((TH1D*)IntStackColl_2b2n[HistNum]->GetStack()->At(7))->GetBinContent(bin)-
		      ((TH1D*)IntStackColl_2b2n[HistNum]->GetStack()->At(6))->GetBinContent(bin));
  TotalMC += par[10]*(((TH1D*)IntStackColl_2b2n[HistNum]->GetStack()->At(9))->GetBinContent(bin)-
		      ((TH1D*)IntStackColl_2b2n[HistNum]->GetStack()->At(8))->GetBinContent(bin));
  TotalMC += par[10]*(((TH1D*)IntStackColl_2b2n[HistNum]->GetStack()->At(11))->GetBinContent(bin)-
		      ((TH1D*)IntStackColl_2b2n[HistNum]->GetStack()->At(10))->GetBinContent(bin));

  // K-40 PMT
  TotalMC += par[11]*(((TH1D*)ExtStackColl_2b2n[HistNum]->GetStack()->At(0))->GetBinContent(bin));
  
  // K-40 Steel Frame
  TotalMC += par[12]*(((TH1D*)ExtStackColl_2b2n[HistNum]->GetStack()->At(8))->GetBinContent(bin) -
		      ((TH1D*)ExtStackColl_2b2n[HistNum]->GetStack()->At(7))->GetBinContent(bin));

  // K-40 Scint Inner
  TotalMC += par[13]*(((TH1D*)ExtStackColl_2b2n[HistNum]->GetStack()->At(15))->GetBinContent(bin) -
		      ((TH1D*)ExtStackColl_2b2n[HistNum]->GetStack()->At(14))->GetBinContent(bin));

  // K-40 Scint Outer
  TotalMC += par[14]*(((TH1D*)ExtStackColl_2b2n[HistNum]->GetStack()->At(16))->GetBinContent(bin) -
		      ((TH1D*)ExtStackColl_2b2n[HistNum]->GetStack()->At(15))->GetBinContent(bin));

  // K-40 Scint Petals
  TotalMC += par[15]*(((TH1D*)ExtStackColl_2b2n[HistNum]->GetStack()->At(17))->GetBinContent(bin) -
		      ((TH1D*)ExtStackColl_2b2n[HistNum]->GetStack()->At(16))->GetBinContent(bin));

  // Bi-214 PMT
  TotalMC += par[16]*(((TH1D*)ExtStackColl_2b2n[HistNum]->GetStack()->At(1))->GetBinContent(bin) -
		      ((TH1D*)ExtStackColl_2b2n[HistNum]->GetStack()->At(0))->GetBinContent(bin));
  
  // Bi-214 Fe Shield
  TotalMC += par[17]*(((TH1D*)ExtStackColl_2b2n[HistNum]->GetStack()->At(4))->GetBinContent(bin) -
		      ((TH1D*)ExtStackColl_2b2n[HistNum]->GetStack()->At(3))->GetBinContent(bin));

  // Bi-214 Steel Frame
  TotalMC += par[18]*(((TH1D*)ExtStackColl_2b2n[HistNum]->GetStack()->At(9))->GetBinContent(bin) -
		      ((TH1D*)ExtStackColl_2b2n[HistNum]->GetStack()->At(8))->GetBinContent(bin));

  // Bi-214 SScin P1
  TotalMC += par[3]*par[19]*(((TH1D*)RadStackColl_2b2n[HistNum]->GetStack()->At(22))->GetBinContent(bin) -
			     ((TH1D*)RadStackColl_2b2n[HistNum]->GetStack()->At(21))->GetBinContent(bin));
  TotalMC += par[3]*par[19]*(((TH1D*)RadStackColl_2b2n[HistNum]->GetStack()->At(24))->GetBinContent(bin) -
			     ((TH1D*)RadStackColl_2b2n[HistNum]->GetStack()->At(23))->GetBinContent(bin));

  // Bi-214 SScin P2
  TotalMC += par[19]*(((TH1D*)RadStackColl_2b2n[HistNum]->GetStack()->At(23))->GetBinContent(bin) -
		      ((TH1D*)RadStackColl_2b2n[HistNum]->GetStack()->At(22))->GetBinContent(bin));
  TotalMC += par[19]*(((TH1D*)RadStackColl_2b2n[HistNum]->GetStack()->At(25))->GetBinContent(bin) -
		      ((TH1D*)RadStackColl_2b2n[HistNum]->GetStack()->At(24))->GetBinContent(bin));

  // Bi214 LSM-Air
  TotalMC += par[20]*(((TH1D*)RadStackColl_2b2n[HistNum]->GetStack()->At(28))->GetBinContent(bin) -
		      ((TH1D*)RadStackColl_2b2n[HistNum]->GetStack()->At(27))->GetBinContent(bin));
  TotalMC += par[20]*(((TH1D*)RadStackColl_2b2n[HistNum]->GetStack()->At(30))->GetBinContent(bin) -
		      ((TH1D*)RadStackColl_2b2n[HistNum]->GetStack()->At(29))->GetBinContent(bin));

  // Tl-208 PMT (including Ac-228)
  TotalMC += par[21]*(((TH1D*)ExtStackColl_2b2n[HistNum]->GetStack()->At(3))->GetBinContent(bin) -
		      ((TH1D*)ExtStackColl_2b2n[HistNum]->GetStack()->At(1))->GetBinContent(bin));

  // Tl-208 Fe Shield (including Ac-228)
  TotalMC += par[22]*(((TH1D*)ExtStackColl_2b2n[HistNum]->GetStack()->At(6))->GetBinContent(bin) -
		      ((TH1D*)ExtStackColl_2b2n[HistNum]->GetStack()->At(4))->GetBinContent(bin));

  // Tl-208 Steel Frame (including Ac-228)
  TotalMC += par[23]*(((TH1D*)ExtStackColl_2b2n[HistNum]->GetStack()->At(11))->GetBinContent(bin) -
		      ((TH1D*)ExtStackColl_2b2n[HistNum]->GetStack()->At(9))->GetBinContent(bin));

  // Tl-208 LSM-Air
  TotalMC += par[24]*(((TH1D*)RadStackColl_2b2n[HistNum]->GetStack()->At(32))->GetBinContent(bin) -
		      ((TH1D*)RadStackColl_2b2n[HistNum]->GetStack()->At(31))->GetBinContent(bin));

  // Co-60 Mu Metal
  TotalMC += par[25]*(((TH1D*)ExtStackColl_2b2n[HistNum]->GetStack()->At(7))->GetBinContent(bin) -
		      ((TH1D*)ExtStackColl_2b2n[HistNum]->GetStack()->At(6))->GetBinContent(bin));

  // Co-60 Steel Frame
  TotalMC += par[26]*(((TH1D*)ExtStackColl_2b2n[HistNum]->GetStack()->At(12))->GetBinContent(bin) -
		      ((TH1D*)ExtStackColl_2b2n[HistNum]->GetStack()->At(11))->GetBinContent(bin));

  // Co-60 Petals
  TotalMC += par[27]*(((TH1D*)ExtStackColl_2b2n[HistNum]->GetStack()->At(13))->GetBinContent(bin) -
		      ((TH1D*)ExtStackColl_2b2n[HistNum]->GetStack()->At(12))->GetBinContent(bin));

  // Co-60 Tower
  TotalMC += par[28]*(((TH1D*)ExtStackColl_2b2n[HistNum]->GetStack()->At(14))->GetBinContent(bin) -
		      ((TH1D*)ExtStackColl_2b2n[HistNum]->GetStack()->At(13))->GetBinContent(bin));

  // Bi210 SScin
  TotalMC += par[29]*(((TH1D*)RadStackColl_2b2n[HistNum]->GetStack()->At(27))->GetBinContent(bin)-
		      ((TH1D*)RadStackColl_2b2n[HistNum]->GetStack()->At(25))->GetBinContent(bin));

  // Bi210 SWire
  TotalMC += par[30]*(((TH1D*)RadStackColl_2b2n[HistNum]->GetStack()->At(5))->GetBinContent(bin)-
		      ((TH1D*)RadStackColl_2b2n[HistNum]->GetStack()->At(3))->GetBinContent(bin));

  // Pa-234m SScin
  TotalMC += par[31]*(((TH1D*)ExtStackColl_2b2n[HistNum]->GetStack()->At(18))->GetBinContent(bin) -
		      ((TH1D*)ExtStackColl_2b2n[HistNum]->GetStack()->At(17))->GetBinContent(bin));

  // g1000 MuMetal P1
  TotalMC += par[32]*(((TH1D*)ExtStackColl_2b2n[HistNum]->GetStack()->At(19))->GetBinContent(bin) -
		      ((TH1D*)ExtStackColl_2b2n[HistNum]->GetStack()->At(18))->GetBinContent(bin));

  // g1000 MuMetal P2
  TotalMC += par[33]*(((TH1D*)ExtStackColl_2b2n[HistNum]->GetStack()->At(20))->GetBinContent(bin) -
		      ((TH1D*)ExtStackColl_2b2n[HistNum]->GetStack()->At(19))->GetBinContent(bin));

  // Neutrons P1
  TotalMC += par[34]*(((TH1D*)ExtStackColl_2b2n[HistNum]->GetStack()->At(21))->GetBinContent(bin) -
		      ((TH1D*)ExtStackColl_2b2n[HistNum]->GetStack()->At(20))->GetBinContent(bin));

  // Neutrons P2
  TotalMC += par[35]*(((TH1D*)ExtStackColl_2b2n[HistNum]->GetStack()->At(22))->GetBinContent(bin) -
		      ((TH1D*)ExtStackColl_2b2n[HistNum]->GetStack()->At(21))->GetBinContent(bin));

  // Bi210 - SFoil SeNew
  TotalMC += par[36]*(((TH1D*)RadStackColl_2b2n[HistNum]->GetStack()->At(17))->GetBinContent(bin)-
		      ((TH1D*)RadStackColl_2b2n[HistNum]->GetStack()->At(15))->GetBinContent(bin));

  // Bi210 - SFoil SeOld
  TotalMC += par[37]*(((TH1D*)RadStackColl_2b2n[HistNum]->GetStack()->At(19))->GetBinContent(bin)-
		      ((TH1D*)RadStackColl_2b2n[HistNum]->GetStack()->At(17))->GetBinContent(bin));

  // Bi210 - SFoil Strip
  TotalMC += par[38]*(((TH1D*)RadStackColl_2b2n[HistNum]->GetStack()->At(21))->GetBinContent(bin)-
		      ((TH1D*)RadStackColl_2b2n[HistNum]->GetStack()->At(19))->GetBinContent(bin));

  // Pa234m - SeNew
  TotalMC += par[39]*(((TH1D*)IntStackColl_2b2n[HistNum]->GetStack()->At(12))->GetBinContent(bin)-
		      ((TH1D*)IntStackColl_2b2n[HistNum]->GetStack()->At(11))->GetBinContent(bin));

  // Pa234m - SeOld
  TotalMC += par[40]*(((TH1D*)IntStackColl_2b2n[HistNum]->GetStack()->At(13))->GetBinContent(bin)-
		      ((TH1D*)IntStackColl_2b2n[HistNum]->GetStack()->At(12))->GetBinContent(bin));

  // K40 - SeNew
  TotalMC += par[41]*(((TH1D*)IntStackColl_2b2n[HistNum]->GetStack()->At(14))->GetBinContent(bin)-
		      ((TH1D*)IntStackColl_2b2n[HistNum]->GetStack()->At(13))->GetBinContent(bin));

  // K40 - SeOld
  TotalMC += par[42]*(((TH1D*)IntStackColl_2b2n[HistNum]->GetStack()->At(15))->GetBinContent(bin)-
		      ((TH1D*)IntStackColl_2b2n[HistNum]->GetStack()->At(14))->GetBinContent(bin));

  // Se - 2b2n SeNew & SeOld
  TotalMC += par[43]* ((TH1D*)SigStackColl_2b2n[HistNum]->GetStack()->At(1))->GetBinContent(bin);

  return TotalMC;
}
