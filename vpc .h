Microsoft Windows [Version 10.0.19045.4894]
(c) Microsoft Corporation. All rights reserved.

C:\Users\Compumart>aws configure
AWS Access Key ID [****************G37W]: ASIAXHLQ2PRMZWM3WZS3
AWS Secret Access Key [****************7/2G]: Iaj9aC5nAOFeFVrvgt4buNgXfnZq+Wv4hrKGeZMU
Default region name [us-east-1]: us-east-1
Default output format [json]: json

C:\Users\Compumart>aws ec2 create-vpc --cidr-block 10.0.0.0/16 --tag-specifications 'ResourceType=vpc,Tags=[{Key=Name,Value="Lab VPC"}]'

Error parsing parameter '--tag-specifications': Expected: '=', received: ''' for input:
'ResourceType=vpc,Tags=[{Key=Name,Value=Lab VPC}]'
^

C:\Users\Compumart>aws ec2 create-vpc --cidr-block 10.0.0.0/16 --tag-specifications "ResourceType=vpc,Tags=[{Key=Name,Value=Lab VPC}]"
{
    "Vpc": {
        "CidrBlock": "10.0.0.0/16",
        "DhcpOptionsId": "dopt-0fabfee6c769769ad",
        "State": "pending",
        "VpcId": "vpc-0950a6d0127f968c4",
        "OwnerId": "496842210393",
        "InstanceTenancy": "default",
        "Ipv6CidrBlockAssociationSet": [],
        "CidrBlockAssociationSet": [
            {
                "AssociationId": "vpc-cidr-assoc-026eba95ea96a43aa",
                "CidrBlock": "10.0.0.0/16",
                "CidrBlockState": {
                    "State": "associated"
                }
            }
        ],
        "IsDefault": false,
        "Tags": [
            {
                "Key": "Name",
                "Value": "Lab VPC"
            }
        ]
    }
}

C:\Users\Compumart>aws ec2 modify-vpc-attribute --vpc-id vpc-0950a6d0127f968c4 --enable-dns-support

C:\Users\Compumart>aws ec2 modify-vpc-attribute --vpc-id vpc-0950a6d0127f968c4 --enable-dns-hostnames

C:\Users\Compumart>
C:\Users\Compumart>aws ec2 create-subnet --vpc-id vpc-0950a6d0127f968c4 --cidr-block 10.0.0.0/24 --availability-zone us-east-1a --tag-specifications "ResourceType=subnet,Tags=[{Key=Name,Value=Public Subnet}]"
{
    "Subnet": {
        "AvailabilityZone": "us-east-1a",
        "AvailabilityZoneId": "use1-az2",
        "AvailableIpAddressCount": 251,
        "CidrBlock": "10.0.0.0/24",
        "DefaultForAz": false,
        "MapPublicIpOnLaunch": false,
        "State": "available",
        "SubnetId": "subnet-0948afb12034ea524",
        "VpcId": "vpc-0950a6d0127f968c4",
        "OwnerId": "496842210393",
        "AssignIpv6AddressOnCreation": false,
        "Ipv6CidrBlockAssociationSet": [],
        "Tags": [
            {
                "Key": "Name",
                "Value": "Public Subnet"
            }
        ],
        "SubnetArn": "arn:aws:ec2:us-east-1:496842210393:subnet/subnet-0948afb12034ea524",
        "EnableDns64": false,
        "Ipv6Native": false,
        "PrivateDnsNameOptionsOnLaunch": {
            "HostnameType": "ip-name",
            "EnableResourceNameDnsARecord": false,
            "EnableResourceNameDnsAAAARecord": false
        }
    }
}


C:\Users\Compumart>
C:\Users\Compumart>aws ec2 create-subnet --vpc-id vpc-0950a6d0127f968c4 --cidr-block 10.0.2.0/23 --availability-zone us-east-1a --tag-specifications "ResourceType=subnet,Tags=[{Key=Name,Value=Private Subnet}]"
{
    "Subnet": {
        "AvailabilityZone": "us-east-1a",
        "AvailabilityZoneId": "use1-az2",
        "AvailableIpAddressCount": 507,
        "CidrBlock": "10.0.2.0/23",
        "DefaultForAz": false,
        "MapPublicIpOnLaunch": false,
        "State": "available",
        "SubnetId": "subnet-0b99dc58766a80667",
        "VpcId": "vpc-0950a6d0127f968c4",
        "OwnerId": "496842210393",
        "AssignIpv6AddressOnCreation": false,
        "Ipv6CidrBlockAssociationSet": [],
        "Tags": [
            {
                "Key": "Name",
                "Value": "Private Subnet"
            }
        ],
        "SubnetArn": "arn:aws:ec2:us-east-1:496842210393:subnet/subnet-0b99dc58766a80667",
        "EnableDns64": false,
        "Ipv6Native": false,
        "PrivateDnsNameOptionsOnLaunch": {
            "HostnameType": "ip-name",
            "EnableResourceNameDnsARecord": false,
            "EnableResourceNameDnsAAAARecord": false
        }
    }
}


C:\Users\Compumart>aws ec2 modify-subnet-attribute --subnet-id subnet-0948afb12034ea524 --map-public-ip-on-launch

C:\Users\Compumart>aws ec2 create-internet-gateway --tag-specifications "ResourceType=internet-gateway,Tags=[{Key=Name,Value=Lab IGW}]"
{
    "InternetGateway": {
        "Attachments": [],
        "InternetGatewayId": "igw-05b8c2fbbefa24a52",
        "OwnerId": "496842210393",
        "Tags": [
            {
                "Key": "Name",
                "Value": "Lab IGW"
            }
        ]
    }
}
C:\Users\Compumart>aws ec2 create-route-table --vpc-id vpc-0950a6d0127f968c4 --tag-specifications "ResourceType=route-table,Tags=[{Key=Name,Value=Public Route Table}]"
{
    "RouteTable": {
        "Associations": [],
        "PropagatingVgws": [],
        "RouteTableId": "rtb-0ddff7ef59dc3fdf4",
        "Routes": [
            {
                "DestinationCidrBlock": "10.0.0.0/16",
                "GatewayId": "local",
                "Origin": "CreateRouteTable",
                "State": "active"
            }
        ],
        "Tags": [
            {
                "Key": "Name",
                "Value": "Public Route Table"
            }
        ],
        "VpcId": "vpc-0950a6d0127f968c4",
        "OwnerId": "496842210393"
    },
    "ClientToken": "39206c23-dcf4-4eaf-b0f3-8baf0d648026"
}


C:\Users\Compumart>aws ec2 create-route --route-table-id rtb-0ddff7ef59dc3fdf4 --destination-cidr-block 0.0.0.0/0 --gateway-id igw-05b8c2fbbefa24a52
{
    "Return": true
}


C:\Users\Compumart>aws ec2 associate-route-table --subnet-id subnet-0948afb12034ea524 --route-table-id rtb-0ddff7ef59dc3fdf4
{
    "AssociationId": "rtbassoc-0de1715d9fa7af610",
    "AssociationState": {
        "State": "associated"
    }
}
C:\Users\Compumart>aws ec2 create-security-group --group-name App-SG --description "Security group for app server" --vpc-id vpc-0950a6d0127f968c4
{
    "GroupId": "sg-0abe956cf3a5e755c"
}


C:\Users\Compumart>aws ec2 authorize-security-group-ingress --group-id sg-0abe956cf3a5e755c --protocol tcp --port 80 --cidr 0.0.0.0/0
{
    "Return": true,
    "SecurityGroupRules": [
        {
            "SecurityGroupRuleId": "sgr-07be1ba7161358858",
            "GroupId": "sg-0abe956cf3a5e755c",
            "GroupOwnerId": "496842210393",
            "IsEgress": false,
            "IpProtocol": "tcp",
            "FromPort": 80,
            "ToPort": 80,
            "CidrIpv4": "0.0.0.0/0"
        }
    ]
}
C:\Users\Compumart>aws ec2 run-instances --image-id ami-0fff1b9a61dec8a5f --count 1 --instance-type t2.micro --key-name vockey --security-group-ids sg-0abe956cf3a5e755c --subnet-id subnet-0948afb12034ea524 --tag-specifications "ResourceType=instance,Tags=[{Key=Name,Value=App Server}]" --user-data '#!/bin/bash
{
    "Groups": [],
    "Instances": [
        {
            "AmiLaunchIndex": 0,
            "ImageId": "ami-0fff1b9a61dec8a5f",
            "InstanceId": "i-0e5e90546e3709b62",
            "InstanceType": "t2.micro",
            "KeyName": "vockey",
            "LaunchTime": "2024-10-08T09:34:40+00:00",
            "Monitoring": {
                "State": "disabled"
            },
            "Placement": {
                "AvailabilityZone": "us-east-1a",
                "GroupName": "",
                "Tenancy": "default"
            },
            "PrivateDnsName": "ip-10-0-0-247.ec2.internal",
            "PrivateIpAddress": "10.0.0.247",
            "ProductCodes": [],
            "PublicDnsName": "",
            "State": {
                "Code": 0,
                "Name": "pending"
            },
            "StateTransitionReason": "",
            "SubnetId": "subnet-0948afb12034ea524",
            "VpcId": "vpc-0950a6d0127f968c4",
            "Architecture": "x86_64",
            "BlockDeviceMappings": [],
            "ClientToken": "ccc3c7eb-907c-47f3-b11a-b5d2845ece83",
            "EbsOptimized": false,
            "EnaSupport": true,
            "Hypervisor": "xen",
            "NetworkInterfaces": [
                {
                    "Attachment": {
                        "AttachTime": "2024-10-08T09:34:40+00:00",
                        "AttachmentId": "eni-attach-0b736534b636a3bc5",
                        "DeleteOnTermination": true,
                        "DeviceIndex": 0,
                        "Status": "attaching",
                        "NetworkCardIndex": 0
                    },
                    "Description": "",
                    "Groups": [
                        {
                            "GroupName": "App-SG",
                            "GroupId": "sg-0abe956cf3a5e755c"
                        }
                    ],
                    "Ipv6Addresses": [],
                    "MacAddress": "12:d1:b4:f8:63:69",
                    "NetworkInterfaceId": "eni-098335b8459ff20a3",
                    "OwnerId": "496842210393",
                    "PrivateDnsName": "ip-10-0-0-247.ec2.internal",
                    "PrivateIpAddress": "10.0.0.247",
                    "PrivateIpAddresses": [
                        {
                            "Primary": true,
                            "PrivateDnsName": "ip-10-0-0-247.ec2.internal",
                            "PrivateIpAddress": "10.0.0.247"
                        }
                    ],
                    "SourceDestCheck": true,
                    "Status": "in-use",
                    "SubnetId": "subnet-0948afb12034ea524",
                    "VpcId": "vpc-0950a6d0127f968c4",
                    "InterfaceType": "interface"
                }
            ],
            "RootDeviceName": "/dev/xvda",
            "RootDeviceType": "ebs",
            "SecurityGroups": [
                {
                    "GroupName": "App-SG",
                    "GroupId": "sg-0abe956cf3a5e755c"
                }
            ],
            "SourceDestCheck": true,
            "StateReason": {
                "Code": "pending",
                "Message": "pending"
            },
            "Tags": [
                {
                    "Key": "Name",
                    "Value": "App Server"
                }
            ],
            "VirtualizationType": "hvm",
            "CpuOptions": {
                "CoreCount": 1,
                "ThreadsPerCore": 1
            },
            "CapacityReservationSpecification": {
                "CapacityReservationPreference": "open"
            },
            "MetadataOptions": {
                "State": "pending",
                "HttpTokens": "required",
                "HttpPutResponseHopLimit": 2,
                "HttpEndpoint": "enabled",
                "HttpProtocolIpv6": "disabled",
                "InstanceMetadataTags": "disabled"
            },
            "EnclaveOptions": {
                "Enabled": false
            },
            "BootMode": "uefi-preferred",
            "PrivateDnsNameOptions": {
                "HostnameType": "ip-name",
                "EnableResourceNameDnsARecord": false,
                "EnableResourceNameDnsAAAARecord": false
            },
            "MaintenanceOptions": {
                "AutoRecovery": "default"
            },
            "CurrentInstanceBootMode": "legacy-bios"
        }
    ],
    "OwnerId": "496842210393",
    "ReservationId": "r-07c87c47fc1242551"
}
C:\Users\Compumart>aws ec2 run-instances --image-id ami-0fff1b9a61dec8a5f --count 1 --instance-type t2.micro --key-name vockey --security-group-ids sg-0abe956cf3a5e755c --subnet-id subnet-0948afb12034ea524 --tag-specifications "ResourceType=instance,Tags=[{Key=Name,Value=App Server}]" --user-data '#!/bin/bash
{
    "Groups": [],
    "Instances": [
        {
            "AmiLaunchIndex": 0,
            "ImageId": "ami-0fff1b9a61dec8a5f",
            "InstanceId": "i-0e40d198d172630b8",
            "InstanceType": "t2.micro",
            "KeyName": "vockey",
            "LaunchTime": "2024-10-08T09:35:43+00:00",
            "Monitoring": {
                "State": "disabled"
            },
            "Placement": {
                "AvailabilityZone": "us-east-1a",
                "GroupName": "",
                "Tenancy": "default"
            },
            "PrivateDnsName": "ip-10-0-0-45.ec2.internal",
            "PrivateIpAddress": "10.0.0.45",
            "ProductCodes": [],
            "PublicDnsName": "",
            "State": {
                "Code": 0,
                "Name": "pending"
            },
            "StateTransitionReason": "",
            "SubnetId": "subnet-0948afb12034ea524",
            "VpcId": "vpc-0950a6d0127f968c4",
            "Architecture": "x86_64",
            "BlockDeviceMappings": [],
            "ClientToken": "aa22fc90-71d3-48d1-b508-e83bf073744f",
            "EbsOptimized": false,
            "EnaSupport": true,
            "Hypervisor": "xen",
            "NetworkInterfaces": [
                {
                    "Attachment": {
                        "AttachTime": "2024-10-08T09:35:43+00:00",
                        "AttachmentId": "eni-attach-04dcc4fc48f7349c5",
                        "DeleteOnTermination": true,
                        "DeviceIndex": 0,
                        "Status": "attaching",
                        "NetworkCardIndex": 0
                    },
                    "Description": "",
                    "Groups": [
                        {
                            "GroupName": "App-SG",
                            "GroupId": "sg-0abe956cf3a5e755c"
                        }
                    ],
                    "Ipv6Addresses": [],
                    "MacAddress": "12:66:df:52:1e:6f",
                    "NetworkInterfaceId": "eni-070db34c74ac67c80",
                    "OwnerId": "496842210393",
                    "PrivateDnsName": "ip-10-0-0-45.ec2.internal",
                    "PrivateIpAddress": "10.0.0.45",
                    "PrivateIpAddresses": [
                        {
                            "Primary": true,
                            "PrivateDnsName": "ip-10-0-0-45.ec2.internal",
                            "PrivateIpAddress": "10.0.0.45"
                        }
                    ],
                    "SourceDestCheck": true,
                    "Status": "in-use",
                    "SubnetId": "subnet-0948afb12034ea524",
                    "VpcId": "vpc-0950a6d0127f968c4",
                    "InterfaceType": "interface"
                }
            ],
            "RootDeviceName": "/dev/xvda",
            "RootDeviceType": "ebs",
            "SecurityGroups": [
                {
                    "GroupName": "App-SG",
                    "GroupId": "sg-0abe956cf3a5e755c"
                }
            ],
            "SourceDestCheck": true,
            "StateReason": {
                "Code": "pending",
                "Message": "pending"
            },
            "Tags": [
                {
                    "Key": "Name",
                    "Value": "App Server"
                }
            ],
            "VirtualizationType": "hvm",
            "CpuOptions": {
                "CoreCount": 1,
                "ThreadsPerCore": 1
            },
            "CapacityReservationSpecification": {
                "CapacityReservationPreference": "open"
            },
            "MetadataOptions": {
                "State": "pending",
                "HttpTokens": "required",
                "HttpPutResponseHopLimit": 2,
                "HttpEndpoint": "enabled",
                "HttpProtocolIpv6": "disabled",
                "InstanceMetadataTags": "disabled"
            },
            "EnclaveOptions": {
                "Enabled": false
            },
            "BootMode": "uefi-preferred",
            "PrivateDnsNameOptions": {
                "HostnameType": "ip-name",
                "EnableResourceNameDnsARecord": false,
                "EnableResourceNameDnsAAAARecord": false
            },
            "MaintenanceOptions": {
                "AutoRecovery": "default"
            },
            "CurrentInstanceBootMode": "legacy-bios"
        }
    ],
    "OwnerId": "496842210393",
    "ReservationId": "r-0e8cfc5fa7ebb16c8"
}


C:\Users\Compumart>