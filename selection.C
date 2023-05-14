/*void smallntuple_chain(char* datafilename)
{i
  TString buffer = datafilename;
  cout<<buffer<<endl;*/
#define _USE_MATH_DEFINES
#include <math.h>
#define M_PI       3.14159265358979323846   // pi
{
	vector<TString> files;
    files.push_back("d1TeV-mu");
	files.push_back("back1-mu");
	const int nfiles = files.size();
	cout<<"file size "<<nfiles<<endl;
  for(int i=0;i<nfiles;i++){
  TString IFile = files.at(i)+".root";
  TFile *ifile = new TFile(IFile);
  TTree *tree = (TTree*)ifile->Get("MyLCTuple");
  int nentries = tree->GetEntries();

  int evevt,trndf,trthn;
  float phi,theta,rcrpx,rcrpy,rcrpz,p1,p2,pt1,pt2,ptll1,ptll2,costheta;
  float	MET,Mll,MET1,MET2,MET21,trch2,pjx,pjy,Eta1,Eta2,Phi1,Phi2,DeltaR;
  float pj1,pj2,pj3,pj4,pj5,pxmu;
  float pxmu1,pxmu2;
  float pymu1,pymu2;
  float pzmu1,pzmu2;
  float pmu1,pmu2;
  float enmu1,enmu2;
  float Phij1,Phij2,Phij3,Etaj1,Etaj2,Etaj3,DeltaR12,DeltaR13,DeltaR23,DeltaRm1j1,DeltaRm2j1,DeltaRm1j2,DeltaRm2j2,DeltaRm1j3,DeltaRm2j3;
  float Phij,Phimu,Etaj,Etamu,DR;
  float pxj,pyj,pzj,enej,pj;
 
  Int_t nj,ntrk,nrec,rctyp,rcntr;
  Float_t rcmox[10000];
  Float_t rcmoy[10000];
  Float_t rcmoz[10000];
  Float_t rcene[10000];
  Float_t rccha[1000];
  Float_t jmox[1000];
  Float_t jmoy[1000];
  Float_t jmoz[1000];
  Float_t jene[1000];

  tree->SetBranchAddress("rctyp",&rctyp);
  tree->SetBranchAddress("rcntr",&rcntr);
  tree->SetBranchAddress("evevt", &evevt);
  tree->SetBranchAddress("nrec", &nrec);
  tree->SetBranchAddress("rcrpx", &rcrpx);
  tree->SetBranchAddress("rcrpy", &rcrpy);
  tree->SetBranchAddress("rcrpz", &rcrpz);
  tree->SetBranchAddress("rcmox", &rcmox);
  tree->SetBranchAddress("rcmoy", &rcmoy); 
  tree->SetBranchAddress("rcmoz", &rcmoz);
  tree->SetBranchAddress("rcene", &rcene);
  tree->SetBranchAddress("nj", &nj);
  tree->SetBranchAddress("jmox", &jmox);
  tree->SetBranchAddress("jmoy", &jmoy);
  tree->SetBranchAddress("jmoz", &jmoz);
  tree->SetBranchAddress("jene", &jene);
  tree->SetBranchAddress("ntrk", &ntrk);
  tree->SetBranchAddress("trndf", &trndf);
  tree->SetBranchAddress("trthn", &trthn);
  tree->SetBranchAddress("trch2", &trch2);

  TString OFile =  "selection"+files.at(i)+".root";
  TFile  *ofile=new TFile(OFile, "recreate");
  TTree *otree = new TTree("tree1","keep events after cut1");
  

  otree->Branch("rctyp",&rctyp,"rctyp/I");
  otree->Branch("rcntr",&rcntr,"rcntr/I");
  otree->Branch("evevt",&evevt,"evevt/I");
  otree->Branch("nrec",&nrec, "nrec/I");
  otree->Branch("nj",&nj, "nj/I");
  otree->Branch("rcrpx", &rcrpx, "rcrpx/F");
  otree->Branch("rcrpy", &rcrpy, "rcrpy/F");
  otree->Branch("rcrpz", &rcrpz, "rcrpz/F");
  otree->Branch("rcmox", &rcmox, "rcmox/F");
  otree->Branch("rcmoy", &rcmoy, "rcmoy/F");
  otree->Branch("rcmoz", &rcmoz, "rcmoz/F");
  otree->Branch("rcene", &rcene, "rcene/F");
  otree->Branch("ntrk", &ntrk, "ntrk/I");
  otree->Branch("p1", &p1, "p1/F");
  otree->Branch("p2", &p2, "p2/F");
  otree->Branch("pt1",&pt1,"pt1/F");
  otree->Branch("pt2",&pt2,"pt2/F");
  otree->Branch("ptll1",&ptll1, "ptll1/F");
  otree->Branch("ptll2",&ptll2,"ptll2/F");
  otree->Branch("costheta",&costheta,"costheta/F");
  otree->Branch("Eta1",&Eta1,"Eta1/F");
  otree->Branch("Eta2",&Eta2,"Eta2/F");
  otree->Branch("Phi1",&Phi1,"Phi1/F");
  otree->Branch("Phi2",&Phi2,"Phi2/F");
  otree->Branch("DeltaR",&DeltaR,"DeltaR/F");
  otree->Branch("DeltaR12",&DeltaR12,"DeltaR12/F");
  otree->Branch("DeltaR13",&DeltaR13,"DeltaR13/F");
  otree->Branch("DeltaR23",&DeltaR23,"DeltaR23/F");
  otree->Branch("pxj",&pxj,"pxj/F");
  otree->Branch("pyj",&pyj,"pyj/F");
  otree->Branch("pzj",&pzj,"pzj/F");
  otree->Branch("pj",&pj,"pj/F");
  otree->Branch("enej",&enej,"enej/F");
  otree->Branch("pymu2",&pymu2,"pymu2/F");
  otree->Branch("pzmu1",&pzmu1,"pzmu1/F");
  otree->Branch("pxmu1",&pxmu1,"pxmu1/F");
  otree->Branch("pxmu2",&pxmu2,"pxmu2/F");
  otree->Branch("pymu1",&pymu1,"pymu1/F");
  otree->Branch("pymu2",&pymu2,"pymu2/F");
  otree->Branch("pzmu1",&pzmu1,"pzmu1/F");
  otree->Branch("pzmu2",&pzmu2,"pzmu2/F");
  otree->Branch("enmu1",&enmu1,"enmu1/F");
  otree->Branch("enmu2",&enmu2,"enmu2/F");
  otree->Branch("pmu1",&pmu1,"pmu1/F");
  otree->Branch("pmu2",&pmu2,"pmu2/F");
  otree->Branch("MET",&MET,"MET/F");
  otree->Branch("Mll",&Mll,"Mll/F");
  TLorentzVector l1,l2,rcmu,rcjet;
    for(int j=0; j<nentries; j++)
    {         
      tree->GetEntry(j);
      if(rctyp!=-13)continue;
      if(nrec!=2)continue;
      for(int i_rec=0; i_rec<nrec;i_rec++){
      rcmu.SetPxPyPzE(rcmox[i_rec],rcmoy[i_rec],rcmoz[i_rec],rcene[i_rec]);
      pxmu=rcmu.Px();
      Phimu=rcmu.Phi();Etamu=rcmu.Eta();
      }
      l1.SetPxPyPzE(rcmox[0],rcmoy[0],rcmoz[0],rcene[0]);
      l2.SetPxPyPzE(rcmox[1],rcmoy[1],rcmoz[1],rcene[1]);
      pxmu1=l1.Px();pymu1=l1.Py();pzmu1=l1.Pz();enmu1=l1.E();pmu1=sqrt(pow(pxmu1,2)+pow(pymu1,2)+pow(pzmu1,2));
      pxmu2=l2.Px();pymu2=l2.Py();pzmu2=l2.Pz();enmu2=l2.E();pmu2=sqrt(pow(pxmu2,2)+pow(pymu2,2)+pow(pzmu2,2));
      
      pt1=sqrt(pow(l1.Px(),2)+pow(l1.Py(),2));
      pt2=sqrt(pow(l2.Px(),2)+pow(l2.Py(),2));
      p1=sqrt(pow(l1.Px(),2)+pow(l1.Py(),2)+pow(l1.Pz(),2));
      p2=sqrt(pow(l2.Px(),2)+pow(l2.Py(),2)+pow(l2.Pz(),2));
      costheta=(l1.Px()*l2.Px()+l1.Py()*l2.Py()+l1.Pz()*l2.Pz())/(p1*p2);
      Mll=(l1+l2).E();
      Eta1=l1.Eta();
      Phi1=l1.Phi();
     
      Eta2=l2.Eta();
      Phi2=l2.Phi();
      if(Phi1>2*M_PI){
      Phi1=Phi1-2*M_PI;
      }
      else{
      Phi1=Phi1;
      }
      if(Phi2>2*M_PI){
      Phi2=Phi2-2*M_PI;
      }
      else{
      Phi2=Phi2;
      }
      DeltaR=sqrt(pow((Eta1-Eta2),2)+pow((Phi1-Phi2),2));
  
      if(pt1>pt2){
      ptll1 = pt1;//leading lepton.
      ptll2 = pt2;
      }
      else{
      ptll1 = pt2;
      ptll2 = pt1;
      }

     
      DeltaRm1j1=sqrt(pow((Phij1-Phi1),2)+pow((Etaj1-Eta1),2));
     // if(DeltaRm1j1<=0.4)continue;
      DeltaRm1j2=sqrt(pow((Phij2-Phi1),2)+pow((Etaj2-Eta1),2));
    //  if(DeltaRm1j2<=0.4)continue;
      DeltaRm1j3=sqrt(pow((Phij3-Phi1),2)+pow((Etaj3-Eta1),2));
    //  if(DeltaRm1j3<=0.4)continue;
      DeltaRm2j1=sqrt(pow((Phij1-Phi2),2)+pow((Etaj1-Eta2),2));
      //if(DeltaRm2j1<=0.4)continue;
      DeltaRm2j2=sqrt(pow((Phij2-Phi2),2)+pow((Etaj2-Eta2),2));
     // if(DeltaRm2j2<=0.4)continue;
      DeltaRm2j3=sqrt(pow((Phij3-Phi2),2)+pow((Etaj3-Eta2),2));
      //if(DeltaRm2j3<=0.4)continue;
      
    //////////////////////////////////////////////////
    // add jets.
	  for(int m=0;m<nj;m++){
      rcjet.SetPxPyPzE(jmox[m],jmoy[m],jmoz[m],jene[m]);
      pxj=rcjet.Px();
      pyj=rcjet.Py();
      pzj=rcjet.Pz();
      pj=sqrt(pow(pxj,2)+pow(pyj,2)+pow(pzj,2));
     if(pj!=pmu2&&pj!=pmu1){
	    for(int n=0;n<nj;n++){
        pxj=pxj+rcjet.Px();
	    pyj=pyj+rcjet.Py();
        pzj=pzj+rcjet.Pz();
		enej=enej+rcjet.E();
      }
 		MET=sqrt(pow((l1+l2).Px()+pxj,2)+pow((l1+l2).Py()+pyj,2));
      }
      else{
     	 MET=sqrt(pow((l1+l2).Px(),2)+pow((l1+l2).Py(),2)); // reduce the muons which are included in jets.
      }
      }
      otree->Fill();
    }      
    
   ofile->Write();
  }
  }  
  

double deltaPhi(const double& phi1, const double& phi2)
{
        double deltaphi = fabs(phi1 - phi2);
        if (deltaphi > 3.141592654) deltaphi = 6.283185308 - deltaphi;
        return deltaphi;
}
