#ifndef CATEGORY_H
#define CATEGORY_H



//---------- full RunII categorization (initial 2014 proposal)

enum Category {
  Untagged     = 0,
  OneJetTagged = 1,
  VBFTagged    = 2, 
  VHLeptTagged = 3, 
  VHHadrTagged = 4, 
  ttHTagged    = 5
};

//int category(
extern "C" int category(
	     int nExtraLep,
	     float ZZPt,
	     float ZZMass,
	     int nCleanedJetsPt30, 
	     int nCleanedJetsPt30BTagged,
	     float* jetpt,
	     float* jeteta,
	     float* jetphi,
	     float* jetmass,
	     float DiJetFisher
	     );



//---------- Moriond 2016 categorization 

enum CategoryMor16 {
  UntaggedMor16  = 0,
  VBFTaggedMor16 = 1
};

extern "C" int categoryMor16(
			     int nCleanedJetsPt30,
			     float pvbf_VAJHU_highestPTJets,
			     float phjj_VAJHU_highestPTJets
			     );



//---------- ICHEP 2016 categorization (temporary version)

enum CategoryIchep16 {
  UntaggedIchep16     = 0,
  VBF1jTaggedIchep16  = 1,
  VBF2jTaggedIchep16  = 2, 
  VHLeptTaggedIchep16 = 3, 
  VHHadrTaggedIchep16 = 4, 
  ttHTaggedIchep16    = 5
};

//int category(
extern "C" int categoryIchep16(
	     int nExtraLep,
	     int nExtraZ,
	     int nCleanedJetsPt30, 
	     int nCleanedJetsPt30BTagged,
	     float* jetQGLikelihood,
	     float phjj_VAJHU_highestPTJets,
	     float phj_VAJHU,
	     float pvbf_VAJHU_highestPTJets,
	     float pAux_vbf_VAJHU,
	     float pwh_hadronic_VAJHU,
	     float pzh_hadronic_VAJHU,
             float* jetPhi,
             float ZZMass,
	     bool useQGTagging = false
	     );



//---------- RunI categorization 

enum CategoryLegacy {
  ZeroOneJet = 0,
  Dijet      = 1
};

extern "C" int categoryLegacy( int nCleanedJetsPt30 );



#endif