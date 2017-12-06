// Copyright (c) 2010 Satoshi Nakamoto
// Copyright (c) 2009-2014 The Bitcoin developers
// Copyright (c) 2014-2015 The Dash developers
// Copyright (c) 2015-2017 The AmsterdamCoin developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.
#include "chainparams.h"
#include "random.h"
#include "util.h"
#include "utilstrencodings.h"
#include <assert.h>
#include <boost/assign/list_of.hpp>
using namespace std;
using namespace boost::assign;
struct SeedSpec6 {
    uint8_t addr[16];
    uint16_t port;
};
#include "chainparamsseeds.h"
/**
 * Main network
 */
//! Convert the pnSeeds6 array into usable address objects.
static void convertSeed6(std::vector<CAddress>& vSeedsOut, const SeedSpec6* data, unsigned int count)
{
    // It'll only connect to one or two seed nodes because once it connects,
    // it'll get a pile of addresses with newer timestamps.
    // Seed nodes are given a random 'last seen time' of between one and two
    // weeks ago.
    const int64_t nOneWeek = 7 * 24 * 60 * 60;
    for (unsigned int i = 0; i < count; i++) {
        struct in6_addr ip;
        memcpy(&ip, data[i].addr, sizeof(ip));
        CAddress addr(CService(ip, data[i].port));
        addr.nTime = GetTime() - GetRand(nOneWeek) - nOneWeek;
        vSeedsOut.push_back(addr);
    }
}
//   What makes a good checkpoint block?
// + Is surrounded by blocks with reasonable timestamps
//   (no blocks before with a timestamp after, none after with
//    timestamp before)
// + Contains no strange transactions
static Checkpoints::MapCheckpoints mapCheckpoints =
    boost::assign::map_list_of
    ( 0, uint256("0x001"));
static const Checkpoints::CCheckpointData data = {
    &mapCheckpoints,
    1512440648, // * UNIX timestamp of last checkpoint block
    0,    // * total number of transactions between genesis and last checkpoint
                //   (the tx=... number in the SetBestChain debug.log lines)
    2000        // * estimated number of transactions per day after checkpoint
};
static Checkpoints::MapCheckpoints mapCheckpointsTestnet =
    boost::assign::map_list_of
    (0, uint256("0x001"));
static const Checkpoints::CCheckpointData dataTestnet = {
    &mapCheckpointsTestnet,
    1512440648,
    0,
    250};
static Checkpoints::MapCheckpoints mapCheckpointsRegtest =
    boost::assign::map_list_of
    (0, uint256("0x001"));
static const Checkpoints::CCheckpointData dataRegtest = {
    &mapCheckpointsRegtest,
    1512440648,
    0,
    100};
class CMainParams : public CChainParams
{
public:
    CMainParams()
    {
        networkID = CBaseChainParams::MAIN;
        strNetworkID = "main";
        /**
         * The message start string is designed to be unlikely to occur in normal data.
         * The characters are rarely used upper ASCII, not valid as UTF-8, and produce
         * a large 4-byte int at any alignment.
         */
        pchMessageStart[0] = 0x75;
        pchMessageStart[1] = 0x18;
        pchMessageStart[2] = 0x78;
        pchMessageStart[3] = 0xd6;
        vAlertPubKey = ParseHex("0419fbebecb2e054c620ef132b2f907014037eb013a6e4972be4289a720b0978fb81f84d5b749d7d0aa1435794ca0bb58e7dae5d515d56c41b123e9");
        nDefaultPort = 50710;
        bnProofOfWorkLimit = ~uint256(0) >> 20; // PUFFScoin starting difficulty is 1 / 2^12
        nSubsidyHalvingInterval = 210000;
        nMaxReorganizationDepth = 100;
        nMinerThreads = 0;
        nTargetTimespan = 1 * 60; // PUFFScoin: 1 minute
        nTargetSpacing = 1 * 60;  // PUFFScoin: 1 minute
        nLastPOWBlock = 10180; // 1 week of POW
        nMaturity = 101;
        nModifierUpdateBlock = 1;
        const char* pszTimestamp = "CBC News 12-17-2017 Police charge 3 after raiding cannabis dispensaries in Sydney, N.S.";
        CMutableTransaction txNew;
        txNew.vin.resize(1);
        txNew.vout.resize(1);
        txNew.vin[0].scriptSig = CScript() << 486604799 << CScriptNum(4) << vector<unsigned char>((const unsigned char*)pszTimestamp, (const unsigned char*)pszTimestamp + strlen(pszTimestamp));
        txNew.vout[0].nValue = 0 * COIN;
        txNew.vout[0].scriptPubKey = CScript() << ParseHex("049ac3bad59db9b5430b911e9a5a4b2f3a76511d414e085eb65bed6dcb7229d36f5f54d48c8fd60b7a2391f0969c6bf64e245260c90a1c630d4f8912") << OP_CHECKSIG;
        genesis.vtx.push_back(txNew);
        genesis.hashPrevBlock = 0;
        genesis.hashMerkleRoot = genesis.BuildMerkleTree();
        genesis.nVersion = 1;
        genesis.nTime = 1512440648;
        genesis.nBits = 0x1e0ffff0;
        genesis.nNonce = 0;
	hashGenesisBlock = uint256("0x01")
        if (true && genesis.GetHash() != hashGenesisBlock)
        {
            Logprintf("recalculating params for mainnet.\n");
            Logprintf("old mainnet genesis nonce: %s\n", genesis.nNonce.ToString().c_str());
            Logprintf("old mainnet genesis hash:  %s\n", hashGenesisBlock.ToString().c_str());
            // deliberately empty for loop finds nonce value.
            for(genesis.nNonce == 0; genesis.GetHash() > bnProofOfWorkLimit; genesis.nNonce++){ } 
            Logprintf("new mainnet genesis merkle root: %s\n", genesis.hashMerkleRoot.ToString().c_str());
            Logprintf("new mainnet genesis nonce: %s\n", genesis.nNonce.ToString().c_str());
            Logprintf("new mainnet genesis hash: %s\n", genesis.GetHash().ToString().c_str());
        }
        hashGenesisBlock = genesis.GetHash();
        assert(hashGenesisBlock == uint256("0x"));
        assert(genesis.hashMerkleRoot == uint256("0x"));
		
        vFixedSeeds.clear();
        vSeeds.clear();
		
        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1, 56); // PUFFScoin mainnet addresses start with P
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1, 80); // PUFFScoin script addresses start with Z
        base58Prefixes[SECRET_KEY] = std::vector<unsigned char>(1, 90); // PUFFScoin private keys start with d
        base58Prefixes[EXT_PUBLIC_KEY] = boost::assign::list_of(0x02)(0x2D)(0x25)(0x33).convert_to_container<std::vector<unsigned char> >();
        base58Prefixes[EXT_SECRET_KEY] = boost::assign::list_of(0x02)(0x21)(0x31)(0x2B).convert_to_container<std::vector<unsigned char> >();
        //  BIP44 coin type is 'TBD'
        base58Prefixes[EXT_COIN_TYPE] = boost::assign::list_of(0x13)(0x00)(0x00)(0x80).convert_to_container<std::vector<unsigned char> >();
        convertSeed6(vFixedSeeds, pnSeed6_main, ARRAYLEN(pnSeed6_main));
        fRequireRPCPassword = true;
        fMiningRequiresPeers = true;
        fAllowMinDifficultyBlocks = false;
        fDefaultConsistencyChecks = false;
        fRequireStandard = true;
        fMineBlocksOnDemand = false;
        fSkipProofOfWorkCheck = false;
        fTestnetToBeDeprecatedFieldRPC = false;
        fHeadersFirstSyncingActive = false;
        nPoolMaxTransactions = 3;
        strSporkKey = "04d6d976efad463fa258e3699e9c3fea60d5168a065abb5829a77448d25e0acbee58bb8f5be56491624b9a48611a8c456a592d45f48ea9c9f0bdc30904534be285";
        
        strObfuscationPoolDummyAddress = "AWSbBnzmNkjDVaYHX7vkL1MqD96pRYWtZo";
        nStartMasternodePayments = 1403728576; //Wed, 25 Jun 2014 20:36:16 GMT
    }
    const Checkpoints::CCheckpointData& Checkpoints() const
    {
        return data;
    }
};
static CMainParams mainParams;
/**
 * Testnet (v3)
 */
class CTestNetParams : public CMainParams
{
public:
    CTestNetParams()
    {
        networkID = CBaseChainParams::TESTNET;
        strNetworkID = "test";
        pchMessageStart[0] = 0x45;
        pchMessageStart[1] = 0x76;
        pchMessageStart[2] = 0x65;
        pchMessageStart[3] = 0xba;
        vAlertPubKey = ParseHex("047c0bdb48eb26bb9ecfe093332d2c236583b2f62f465273175fb2c7f2aa49ad3e9a2357574a74fd6cf25e9774bba8951daab94c426af8c66df8c70f");
        nDefaultPort = 50712;
        nMinerThreads = 0;
        nTargetTimespan = 1 * 60; // PUFFScoin: 1 day
        nTargetSpacing = 1 * 60;  // PUFFScoin: 1 minute
        nLastPOWBlock = 200;
        nMaturity = 15;
        //! Modify the testnet genesis block so the timestamp is valid for a later start.
        genesis.nTime = 1512440648;
        genesis.nNonce = 0;
	hashGenesisBlock = uint256("0x01")
        if (true && genesis.GetHash() != hashGenesisBlock)
        {
            Logprintf("recalculating params for mainnet.\n");
            Logprintf("old testnet genesis nonce: %s\n", genesis.nNonce.ToString().c_str());
            Logprintf("old testnet genesis hash:  %s\n", hashGenesisBlock.ToString().c_str());
            // deliberately empty for loop finds nonce value.
            for(genesis.nNonce == 0; genesis.GetHash() > bnProofOfWorkLimit; genesis.nNonce++){ } 
            Logprintf("new testnet genesis merkle root: %s\n", genesis.hashMerkleRoot.ToString().c_str());
            Logprintf("new testnet genesis nonce: %s\n", genesis.nNonce.ToString().c_str());
            Logprintf("new testnet genesis hash: %s\n", genesis.GetHash().ToString().c_str());
        }
        hashGenesisBlock = genesis.GetHash();
        //assert(hashGenesisBlock == uint256("0x"));
        vFixedSeeds.clear();
        vSeeds.clear();
        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1, 139); // Testnet PUFFScoin addresses start with 'x' or 'y'
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1, 19);  // Testnet PUFFScoin script addresses start with '8' or '9'
        base58Prefixes[SECRET_KEY] = std::vector<unsigned char>(1, 239);     // Testnet private keys start with '9' or 'c' (Bitcoin defaults)
        // Testnet PUFFScoin BIP32 pubkeys start with 'DRKV'
        base58Prefixes[EXT_PUBLIC_KEY] = boost::assign::list_of(0x3a)(0x80)(0x61)(0xa0).convert_to_container<std::vector<unsigned char> >();
        // Testnet PUFFScoin BIP32 prvkeys start with 'DRKP'
        base58Prefixes[EXT_SECRET_KEY] = boost::assign::list_of(0x3a)(0x80)(0x58)(0x37).convert_to_container<std::vector<unsigned char> >();
        // Testnet PUFFScoin BIP44 coin type is '1' (All coin's testnet default)
        base58Prefixes[EXT_COIN_TYPE] = boost::assign::list_of(0x01)(0x00)(0x00)(0x80).convert_to_container<std::vector<unsigned char> >();
        convertSeed6(vFixedSeeds, pnSeed6_test, ARRAYLEN(pnSeed6_test));
        fRequireRPCPassword = true;
        fMiningRequiresPeers = true;
        fAllowMinDifficultyBlocks = true;
        fDefaultConsistencyChecks = false;
        fRequireStandard = false;
        fMineBlocksOnDemand = false;
        fTestnetToBeDeprecatedFieldRPC = true;
        nPoolMaxTransactions = 2;
        strSporkKey = "04348C2F50F90267E64FACC65BFDC9D0EB147D090872FB97ABAE92E9A36E6CA60983E28E741F8E7277B11A7479B626AC115BA31463AC48178A5075C5A9319D4A38";
        strObfuscationPoolDummyAddress = "y57cqfGRkekRyDRNeJiLtYVEbvhXrNbmox";
        nStartMasternodePayments = 1420837558; //Fri, 09 Jan 2015 21:05:58 GMT
    }
    const Checkpoints::CCheckpointData& Checkpoints() const
    {
        return dataTestnet;
    }
};
static CTestNetParams testNetParams;
/**
 * Regression test
 */
class CRegTestParams : public CTestNetParams
{
public:
    CRegTestParams()
    {
        networkID = CBaseChainParams::REGTEST;
        strNetworkID = "regtest";
        strNetworkID = "regtest";
        pchMessageStart[0] = 0xa1;
        pchMessageStart[1] = 0xcf;
        pchMessageStart[2] = 0x7e;
        pchMessageStart[3] = 0xac;
        nSubsidyHalvingInterval = 150;
        nMinerThreads = 1;
        nTargetTimespan = 24 * 60 * 60; // PUFFScoin: 1 day
        nTargetSpacing = 1 * 60;        // PUFFScoin: 1 minutes
        bnProofOfWorkLimit = ~uint256(0) >> 1;
        genesis.nTime = 1512440648;
        genesis.nBits = 0x207fffff;
        genesis.nNonce = 12345;
	hashGenesisBlock = uint256("0x01")
        if (true && genesis.GetHash() != hashGenesisBlock)
        {
            Logprintf("recalculating params for mainnet.\n");
            Logprintf("old regtest genesis nonce: %s\n", genesis.nNonce.ToString().c_str());
            Logprintf("old regtest genesis hash:  %s\n", hashGenesisBlock.ToString().c_str());
            // deliberately empty for loop finds nonce value.
            for(genesis.nNonce == 0; genesis.GetHash() > bnProofOfWorkLimit; genesis.nNonce++){ } 
            Logprintf("new regtest genesis merkle root: %s\n", genesis.hashMerkleRoot.ToString().c_str());
            Logprintf("new regtest genesis nonce: %s\n", genesis.nNonce.ToString().c_str());
            Logprintf("new regtest genesis hash: %s\n", genesis.GetHash().ToString().c_str());
        }
        hashGenesisBlock = genesis.GetHash();
        nDefaultPort = 51476;
        //assert(hashGenesisBlock == uint256("0x4f023a2120d9127b21bbad01724fdb79b519f593f2a85b60d3d79160ec5f29df"));
        vFixedSeeds.clear(); //! Testnet mode doesn't have any fixed seeds.
        vSeeds.clear();      //! Testnet mode doesn't have any DNS seeds.
        fRequireRPCPassword = false;
        fMiningRequiresPeers = false;
        fAllowMinDifficultyBlocks = true;
        fDefaultConsistencyChecks = true;
        fRequireStandard = false;
        fMineBlocksOnDemand = true;
        fTestnetToBeDeprecatedFieldRPC = false;
    }
    const Checkpoints::CCheckpointData& Checkpoints() const
    {
        return dataRegtest;
    }
};
static CRegTestParams regTestParams;
/**
 * Unit test
 */
class CUnitTestParams : public CMainParams, public CModifiableParams
{
public:
    CUnitTestParams()
    {
        networkID = CBaseChainParams::UNITTEST;
        strNetworkID = "unittest";
        nDefaultPort = 50712;
        vFixedSeeds.clear(); //! Unit test mode doesn't have any fixed seeds.
        vSeeds.clear();      //! Unit test mode doesn't have any DNS seeds.
        fRequireRPCPassword = false;
        fMiningRequiresPeers = false;
        fDefaultConsistencyChecks = true;
        fAllowMinDifficultyBlocks = false;
        fMineBlocksOnDemand = true;
    }
    const Checkpoints::CCheckpointData& Checkpoints() const
    {
        // UnitTest share the same checkpoints as MAIN
        return data;
    }
    //! Published setters to allow changing values in unit test cases
    virtual void setSubsidyHalvingInterval(int anSubsidyHalvingInterval) { nSubsidyHalvingInterval = anSubsidyHalvingInterval; }
    virtual void setDefaultConsistencyChecks(bool afDefaultConsistencyChecks) { fDefaultConsistencyChecks = afDefaultConsistencyChecks; }
    virtual void setAllowMinDifficultyBlocks(bool afAllowMinDifficultyBlocks) { fAllowMinDifficultyBlocks = afAllowMinDifficultyBlocks; }
    virtual void setSkipProofOfWorkCheck(bool afSkipProofOfWorkCheck) { fSkipProofOfWorkCheck = afSkipProofOfWorkCheck; }
};
static CUnitTestParams unitTestParams;
static CChainParams* pCurrentParams = 0;
CModifiableParams* ModifiableParams()
{
    assert(pCurrentParams);
    assert(pCurrentParams == &unitTestParams);
    return (CModifiableParams*)&unitTestParams;
}
const CChainParams& Params()
{
    assert(pCurrentParams);
    return *pCurrentParams;
}
CChainParams& Params(CBaseChainParams::Network network)
{
    switch (network) {
    case CBaseChainParams::MAIN:
        return mainParams;
    case CBaseChainParams::TESTNET:
        return testNetParams;
    case CBaseChainParams::REGTEST:
        return regTestParams;
    case CBaseChainParams::UNITTEST:
        return unitTestParams;
    default:
        assert(false && "Unimplemented network");
        return mainParams;
    }
}
void SelectParams(CBaseChainParams::Network network)
{
    SelectBaseParams(network);
    pCurrentParams = &Params(network);
}
bool SelectParamsFromCommandLine()
{
    CBaseChainParams::Network network = NetworkIdFromCommandLine();
    if (network == CBaseChainParams::MAX_NETWORK_TYPES)
        return false;
    SelectParams(network);
    return true;
}
