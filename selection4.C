/*void smallntuple_chain(char* datafilename)
{i
  TString buffer = datafilename;
  cout<<buffer<<endl;*/
#define _USE_MATH_DEFINES
#include <math.h>
#define M_PI       3.14159265358979323846   // pi
{
	vector<TString> files;
//	files.push_back("d1TeV");
//	files.push_back("back1");
//	files.push_back("back2");
//	files.push_back("back3");
//	files.push_back("back4");
//	files.push_back("back5");
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
  float pyj1,pyj2,pyj3,pyj4,pyj5;
  float pxj1,pxj2,pxj3,pxj4,pxj5;
  float pzj1,pzj2,pzj3,pzj4,pzj5;
  float enj1,enj2,enj3,enj4,enj5;
  float pj1,pj2,pj3,pj4,pj5,pxmu,pxj;
  float pxmu1,pxmu2;
  float pymu1,pymu2;
  float pzmu1,pzmu2;
  float pmu1,pmu2;
  float enmu1,enmu2;
  float Phij1,Phij2,Phij3,Etaj1,Etaj2,Etaj3,DeltaR12,DeltaR13,DeltaR23,DeltaRm1j1,DeltaRm2j1,DeltaRm1j2,DeltaRm2j2,DeltaRm1j3,DeltaRm2j3;
  float Phij,Phimu,Etaj,Etamu,DR;
 
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
  otree->Branch("pxj1",&pxj1,"pxj1/F");
  otree->Branch("pxj2",&pxj2,"pxj2/F");
  otree->Branch("pxj3",&pxj3,"pxj3/F");
  otree->Branch("pxj4",&pxj4,"pxj4/F");
  otree->Branch("pxj5",&pxj5,"pxj5/F");
  otree->Branch("pyj1",&pyj1,"pyj1/F");
  otree->Branch("pyj2",&pyj2,"pyj2/F");
  otree->Branch("pyj3",&pyj3,"pyj3/F");
  otree->Branch("pyj4",&pyj4,"pyj4/F");
  otree->Branch("pyj5",&pyj5,"pyj5/F");
  otree->Branch("pzj1",&pzj1,"pzj1/F");
  otree->Branch("pzj2",&pzj2,"pzj2/F");
  otree->Branch("pzj3",&pzj3,"pzj3/F");
  otree->Branch("pzj4",&pzj4,"pzj4/F");
  otree->Branch("pzj5",&pzj5,"pzj5/F");
  otree->Branch("pj1",&pj1,"pj1/F");
  otree->Branch("pj2",&pj2,"pj2/F");
  otree->Branch("pj3",&pj3,"pj3/F");
  otree->Branch("pj4",&pj4,"pj4/F");
  otree->Branch("pj5",&pj5,"pj5/F");
  otree->Branch("enj1",&enj1,"enj1/F");
  otree->Branch("enj2",&enj2,"enj2/F");
  otree->Branch("enj3",&enj3,"enj3/F");
  otree->Branch("enj4",&enj4,"enj4/F");
  otree->Branch("enj5",&enj5,"enj5/F");
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
  TLorentzVector l1,l2,l3,le1,le2,le3,le4,le5,rcmu,rca,rca1,rca2,rca3,rca4,lj1,lj2,lj3,lj4,lj5,rjet,lp1,lp2,lp3,lp4;
    for(int j=0; j<nentries; j++)
    {         
      tree->GetEntry(j);
      for(int m=0; m<nj;m++){
      rjet.SetPxPyPzE(jmox[m],jmoy[m],jmoz[m],jene[m]);
      pxj=rjet.Px();
      Phij=rjet.Phi();Etaj=rjet.Eta();
      }
      lj1.SetPxPyPzE(jmox[0],jmoy[0],jmoz[0],jene[0]);
      pxj1=lj1.Px();pyj1=lj1.Py();pzj1=lj1.Pz();enj1=lj1.E();pj1=sqrt(pow(pxj1,2)+pow(pyj1,2)+pow(pzj1,2));
      Phij1=lj1.Phi();Etaj1=lj1.Eta();
      if(Phij1>2*M_PI){Phij1=Phij1-2*M_PI;}
      else{Phij1=Phij1;}
      
      lj2.SetPxPyPzE(jmox[1],jmoy[1],jmoz[1],jene[1]);
      pxj2=lj2.Px();pyj2=lj2.Py();pzj2=lj2.Pz();enj2=lj2.E();pj2=sqrt(pow(pxj2,2)+pow(pyj2,2)+pow(pzj2,2));
      Phij2=lj2.Phi();Etaj2=lj2.Eta();
      if(Phij2>2*M_PI){Phij2=Phij2-2*M_PI;}
      else{Phij2=Phij2;}
      
      lj3.SetPxPyPzE(jmox[2],jmoy[2],jmoz[2],jene[2]);
      pxj3=lj3.Px();pyj3=lj3.Py();pzj3=lj3.Pz();enj3=lj3.E();pj3=sqrt(pow(pxj3,2)+pow(pyj3,2)+pow(pzj3,2));
      Phij3=lj3.Phi();Etaj3=lj3.Eta();
      if(Phij3>2*M_PI){Phij3=Phij3-2*M_PI;}
      else{Phij3=Phij3;}

      pjx=(lj1+lj2+lj3).Px();
      pjy=(lj1+lj2+lj3).Py();
      
      DeltaR12=sqrt(pow((Phij1-Phij2),2)+pow((Etaj1-Etaj2),2));
     // if(DeltaR12<=0.4)continue;
      DeltaR13=sqrt(pow((Phij1-Phij3),2)+pow((Etaj1-Etaj3),2));
     // if(DeltaR13<=0.4)continue;
      DeltaR23=sqrt(pow((Phij2-Phij3),2)+pow((Etaj2-Etaj3),2));
      //if(DeltaR23<=0.4)continue;
      
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
    // if(DeltaR<=0.4)continue;
      if(nj!=2){
      MET=sqrt(pow((l1+l2).Px()+pxj1,2)+pow((l1+l2).Py()+pyj1,2));
      }
      else{
      MET=sqrt(pow((l1+l2).Px(),2)+pow((l1+l2).Py(),2));
      }//the max nj is 3, so only count one jet.
     
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
