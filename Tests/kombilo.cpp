#include "search.h"
#include "tester.h"
#include "SGFFile.h"
#include <string>
#include "binaryDescribe.h"

using namespace std;


int ReadSgf(testLogger& log);

int main(int argc, char** argv) {
    GameList NewDb("db/test.db");
    Test ("Reading in a basic sgf...",ReadSgf).RunTest();
    return 0;
}

int ReadSgf(testLogger& log) {
    string sgfData = "b'(;FF[4]GM[1]SZ[19]CA[UTF-8]SO[gokifu.com]BC[kr]WC[kr]EV[]PB[Cho Hanseung]BR[9p]PW[Lee Sedol]WR[9p]KM[6.5]DT[2014-01-02]RE[B+R];B[qd];W[pp];B[dc];W[cp];B[eq];W[ce];B[mp];W[qn];B[dn];W[ep];B[dp];W[do];B[dq];W[co];B[eo];W[fp];B[cq];W[cn];B[fo];W[gp];B[go];W[hp];B[ho];W[ip];B[dm];W[bl];B[bp];W[bo];B[cm];W[bm];B[ao];W[bn];B[br];W[dk];B[io];W[jp];B[kn];W[fk];B[oq];W[lq];B[pq];W[qq];B[lp];W[mq];B[kq];W[kr];B[kp];W[jr];B[qr];W[jo];B[jn];W[qp];B[rr];W[or];B[nr];W[nq];B[pr];W[np];B[ed];W[im];B[in];W[fm];B[mr];W[no];B[hm];W[kc];B[ic];W[oc];B[mc];W[pe];B[qe];W[pf];B[qg];W[ld];B[pc];W[ob];B[df];W[cg];B[hk];W[dg];B[eg];W[eh];B[fh];W[ei];B[lr];W[fq];B[mn];W[er];B[dr];W[om];B[pb];W[qf];B[rf];W[pd];B[qc];W[pg];B[qh];W[re];B[rh];W[pa];B[qa];W[oa];B[rd];W[id];B[hd];W[jd];B[jb];W[kb];B[he];W[cc];B[cb];W[cd];B[fr];W[gr];B[es];W[ir];B[bb];W[gl];B[hl];W[en];B[nd];W[od];B[nf];W[md];B[nk];W[mg];B[ng];W[nh];B[oh];W[mh];B[og];W[ne];B[ql];W[ok];B[nl];W[qk];B[ol];W[rl];B[pk];W[qm];B[pl];W[qj];B[mf];W[kg];B[sp];W[ro];B[ef];W[lj];B[kk];W[lk];B[ll];W[hc];B[hb];W[gc];B[gb];W[fc];B[fb];W[hf];B[gf];W[ml];B[kj];W[ie];B[hg];W[if];B[fe];W[lm];B[kl];W[ph];B[ni];W[mm];B[mk];W[ln];B[nm];W[mo];B[ko];W[li];B[nn];W[lo];B[pm];W[ri];B[op];W[oo];B[po];W[pn];B[on];W[qo];B[jh];W[qi];B[oi];W[sh];B[rg];W[gj];B[jg];W[jf];B[kh];W[lg];B[fi];W[fj];B[ae];W[bf];B[hi];W[so];B[me];W[oe];B[le];W[ke];B[fn];W[em];B[km];W[po];B[ls];W[sq];B[rq];W[rp];B[sr];W[pi];B[gm];W[an];B[ap];W[bc];B[ac];W[af];B[ad];W[cf];B[ig];W[hj];B[ij];W[gi];B[gh];W[dd];B[ec])'";

    SGFFile file = SGFFile::OpenFile("sgfs/1mx2-gokifu-20140102-Cho_Hanseung-Lee_Sedol.sgf");

    if ( file.Directory() != "sgfs") {
        log << "Directory returned incorrect path";
        return 1;
    }

    if ( file.Name() != "1mx2-gokifu-20140102-Cho_Hanseung-Lee_Sedol.sgf") {
        log << "Name return the wrong file name";
        log << file.Name();
        return 2;
    }

    if ( file.Path() != "sgfs/1mx2-gokifu-20140102-Cho_Hanseung-Lee_Sedol.sgf" ) {
        log << "Path returned the incorrect path!" << endl;
        return 3;
    }

    string gotData = file.SGF();

    if ( gotData != sgfData ) {
        log << "Miss-match in sgf data!" << endl;
        return 4;
    }

    return 0;

}
