{
#include "TAxis.h"
#include "TH2.h"
#include "TStyle.h"
#include "TCanvas.h"
#include "TNtupleD.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <TLatex.h>
//#include "windows.h"
//#include <vector.h>



	TFile * input1 = new TFile ("ntuple_mu-d1TeV.root");
        input1->cd("");
        TTree *Outtree1 = (TTree*)input1->Get("tree");

        TFile * input2 = new TFile ("selectiond1TeV-mu.root");
        input2->cd("");
        TTree *Outtree2 = (TTree*)input2->Get("tree1");

	 TFile * input3 = new TFile ("ntuple_mu-back1.root");
        input3->cd("");
        TTree *Outtree3 = (TTree*)input3->Get("tree");
	
	 TFile * input4 = new TFile ("selectionback1-mu.root");
        input4->cd("");
        TTree *Outtree4 = (TTree*)input4->Get("tree1");


 
 
       int nentries1 = (int)Outtree1->GetEntries();
       cout<<"nentries1 = "<<nentries1<<endl;
   
       int nentries2 = (int)Outtree2->GetEntries();
       cout<<"nentries2 = "<<nentries2<<endl;
   
     
       int nentries3 = (int)Outtree3->GetEntries();
       cout<<"nentries3 = "<<nentries3<<endl;

       int nentries4 = (int)Outtree4->GetEntries();
       cout<<"nentries4 = "<<nentries4<<endl;

   
       TH1D *PTA1   = new TH1D("a"," ",20,-1.5,1.5);
//       PTA1->Sumw2();
       TH1D *PTA2   = new TH1D("b"," ",20,-1.5,1.5);
  //     PTA2->Sumw2();
  //
       TH1D *PTA3   = new TH1D("c"," ",20,-1.5,1.5);

       TH1D *PTA4   = new TH1D("d"," ",20,-1.5,1.5);
  
  

      // double ;	
        double metaMu1,metaMu3,metaMu5,metaMu6;
	float metaMu2,metaMu4;
       Outtree1->SetBranchAddress("costheta"    ,&metaMu1);
       Outtree2->SetBranchAddress("costheta"    ,&metaMu2);
       Outtree3->SetBranchAddress("costheta"    ,&metaMu3);
       Outtree4->SetBranchAddress("costheta"    ,&metaMu4);

      for(int i=0; i<nentries1; i++)
     {
         Outtree1->GetEntry(i);
         PTA1->Fill(metaMu1,0.4372*1000./float(nentries1));
     } 

      for(int i=0; i<nentries2; i++)
     {
         Outtree2->GetEntry(i);
         PTA2->Fill(metaMu2,0.4372*1000./float(nentries2));
     } 
     
         for(int i=0; i<nentries3; i++)
     {
         Outtree3->GetEntry(i);
         PTA3->Fill(metaMu3,0.2543*1000./float(nentries3));
     }

	   for(int i=0; i<nentries4; i++)
     {
         Outtree4->GetEntry(i);
         PTA4->Fill(metaMu4,0.2543*1000./float(nentries4));
     }
   

      TCanvas *c01 = new TCanvas("c01","",700,600);
      c01->SetLogy();
//      PTA3->SetTitle("the  distribution of mu+");
      PTA1->GetXaxis()->SetTitle("cos#theta_{ll}");
      PTA1->GetYaxis()->SetTitleOffset(0.90);
      PTA1->GetYaxis()->SetLabelSize(0.045);
      PTA1->GetYaxis()->SetTitleSize(0.05);
      PTA1->GetYaxis()->SetTitle("Events/bin");
     // PTA1->GetXaxis()->CenterTitle();
     // PTA1->GetYaxis()->CenterTitle();
      PTA1->SetStats(false);
      PTA1->SetMinimum(0.1);
      PTA1->SetMaximum(100000);
      //PTA3->SetMaximum(100);
      PTA1->SetLineColor(4);
      PTA1->SetLineWidth(2);
      PTA1->SetMarkerStyle(20);
      PTA1->GetXaxis()->SetLabelSize(0.045);
      PTA1->GetXaxis()->SetTitleOffset(0.85);
      PTA1->GetXaxis()->SetTitleSize(0.05);
  //    PTA1->GetXaxis()->SetTitleOffset(1.4);
      PTA1->Draw("HIST e");

      PTA2->SetLineColor(3);
      PTA2->SetLineWidth(2);
      PTA2->SetMarkerStyle(21);
      PTA2->SetLineStyle(9);
      PTA2->SetStats(false);
      PTA2->Draw("HIST e sames");

      PTA3->SetLineColor(2);
      PTA3->SetLineWidth(2);
      PTA3->SetMarkerStyle(21);
  //    PTA3->SetLineStyle(9);
      PTA3->SetStats(false);
      PTA3->Draw("HIST e sames");

      PTA4->SetLineColor(5);
      PTA4->SetLineWidth(2);
      PTA4->SetMarkerStyle(21);
      PTA4->SetLineStyle(9);
      PTA4->SetStats(false);
      PTA4->Draw("HIST e sames");

     TLegend *l1 = new TLegend(0.76,0.74,0.89,0.89);
      l1->SetNColumns(2);
     l1->SetBorderSize(1);
     l1->SetFillColor(0);
     l1->AddEntry(PTA1,"#mu^{+}#mu^{+}");
     l1->AddEntry(PTA2,"#mu^{+}#mu^{+}_full simulation");
  //   l1->AddEntry(PTA3,"#mu^{+}#mu^{+}w^{+}w^{+}_full simulation");
     l1->AddEntry(PTA3,"#mu^{+}#mu^{+}w^{+}w^{+}");
     l1->AddEntry(PTA4,"#mu^{+}#mu^{+}w^{+}w^{+}_full simulation");
     l1->Draw("Sames");
  

  /*    TLatex *t = new TLatex();
     t->SetNDC();
     t->SetTextAlign(23);
     t->SetTextFont(64);
     t->SetTextSizePixels(20);
     t->DrawLatex(0.55,0.90,"the distribution of Ptll");
     t->Draw();*/

     c01->SaveAs("compare-pthh.png");

}
