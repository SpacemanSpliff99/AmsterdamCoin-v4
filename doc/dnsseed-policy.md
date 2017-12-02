Expectations for DNS Seed operators
====================================

PUFFScoin Core attempts to minimize the level of trust in DNS seeds, which are DNS servers that return the IP addresses of active full nodes running on the on the PUFFScoin network to assist in peer discovery. Public DNS servers, being arbitrarily exposed to the homogenous PUFFScoin network, still pose a small amount of risk to the network. As such, for best practice network security, these DNS seeds must be run by entities which have some minimum level of trust within the PUFFScoin community.

Other implementations and applications run alongside the PUFFScoin client may also utilize the same DNS seeds and, thus, these seeds may be more exposed to the outside network. In light of this exposure this document establishes some basic expectations for the expectations for the operation of dnsseeds.

0. A DNS seed operating organization or person is expected to follow good host security practices and maintain control of their serving infrastructure and not sell or transfer control of their DNS seed. Any hosting services contracted by the operator are equally expected to uphold these expectations.

1. The DNS seed results must consist exclusively of fairly selected and functioning PUFFScoin nodes from the public network to the best of the operators understanding and capability.

2. For the avoidance of doubt, the results may be randomized but must not single-out any group of hosts to receive different results unless due to an urgent technical necessity and disclosed.

3. The results may not be served with a DNS TTL of less than one minute.

4. Any logging of DNS queries should be only that which is necessary for the operation of the service or urgent health of the PUFFScoin
network and must not be retained longer than necessary or disclosed to any third party.

5. Information gathered as a result of the operators node-spidering (not from DNS queries) may be freely published or retained, but only if this data was not made more complete by biasing node connectivity (a violation of expectation (1)).

6. Operators are encouraged, but not required, to publicly document the details of their operating practices.

7. A reachable email contact address must be published for inquiries related to the DNS seed operation.

If these expectations cannot be satisfied the operator should discontinue providing services and contact the active PUFFScoin Core development team as well as posting on the [PuffsCoin Forum](https://forum.puffscoin.com).

Behavior outside of these expectations may be reasonable in some situations but should be discussed in public in advance.

See also
----------
- [puffscoin-seeder](https://github.com/SpacemanSpliff99/puffscoin-seeder) is a reference implementation of a DNS seed.

**NOTE** the puffscoin seeder is still a referrence to BTC. This will be updated after Genesis as soon as we can get it associated to the PUFFScoin network.
