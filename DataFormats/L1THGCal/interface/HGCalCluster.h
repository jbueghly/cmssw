#ifndef DataFormats_L1Trigger_HGCalCluster_h
#define DataFormats_L1Trigger_HGCalCluster_h

#include "DataFormats/L1Trigger/interface/L1Candidate.h"
#include "DataFormats/L1Trigger/interface/BXVector.h"

namespace l1t {
  
  class HGCalCluster : public L1Candidate {
    public:
        // FIXME: remnants of Stage-2 calo trigger to be removed
      enum ClusterFlag{
        INCLUDE_SEED        = 0,
        INCLUDE_NW          = 1,
        INCLUDE_N           = 2,
        INCLUDE_NE          = 3,
        INCLUDE_E           = 4,
        INCLUDE_SE          = 5,
        INCLUDE_S           = 6,
        INCLUDE_SW          = 7,
        INCLUDE_W           = 8,
        INCLUDE_NN          = 9,
        INCLUDE_SS          = 10,
        TRIM_LEFT           = 11,
        IS_SECONDARY        = 12,
        MERGE_UPDOWN        = 13, // 0=up, 1=down
        MERGE_LEFTRIGHT     = 14 // 0=left, 1=right
      };

    public:
      HGCalCluster(){}
      HGCalCluster( const LorentzVector p4,
          int pt=0,
          int eta=0,
          int phi=0
          );

      ~HGCalCluster();




      void setClusterFlag(ClusterFlag flag, bool val=true);
      void setHwPtEm( int pt );
      void setHwPtHad( int pt );
      void setHwSeedPt(int pt);
      void setFgEta(int fgEta);
      void setFgPhi(int fgPhi);
      void setHOverE(int hOverE);
      void setFgECAL(int fgECAL);

      bool checkClusterFlag(ClusterFlag flag) const;
      bool isValid() const;
      int hwPtEm() const;
      int hwPtHad() const;
      int hwSeedPt() const;
      int fgEta() const;
      int fgPhi() const;
      int hOverE() const;
      int fgECAL() const;
      int clusterFlags() const{return m_clusterFlags;}

      bool operator<(const HGCalCluster& cl) const;
      bool operator>(const HGCalCluster& cl) const {return  cl<*this;};
      bool operator<=(const HGCalCluster& cl) const {return !(cl>*this);};
      bool operator>=(const HGCalCluster& cl) const {return !(cl<*this);};

    private:
      // Summary of clustering outcomes
      int m_clusterFlags; // see ClusterFlag bits (15 bits, will evolve)

      // Energies
      int m_hwPtEm;
      int m_hwPtHad;
      int m_hwSeedPt;

      // fine grained position
      int m_fgEta; // 2 bits (to be defined in agreement with GT inputs)
      int m_fgPhi; // 2 bits (to be defined in agreement with GT inputs)

      // identification variables
      int m_hOverE; // 8 bits (between 0 and 1 -> resolution=1/256=0.39%). Number of bits is not definitive
      int m_fgECAL; // FG bit of the seed tower
  };

  typedef BXVector<HGCalCluster> HGCalClusterBxCollection;

  
}

#endif
