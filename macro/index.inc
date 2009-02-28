<?xml version="1.0" encoding="x-sjis-cp932"?>
<!-- 
index.inc : �����}�N��
2005 <nakajima@netstock.co.jp>
�g�p�@�F�{���ŁA<INDEX reading="����" term="���"/>��� �̂悤�ɂ��Ă����A
        �Ⴆ�Ύ��̂悤�ɖ{���̌�ɍ��������
        <BODY cols="3">
        <H3>����</H3>
        <MAKEINDEX/>
        </BODY>
-->

<do>

<!--
  �ǂ݂�������̓����������o���T�u���[�`��
-->
<eval>
  my @kindextitle = (
    [qw(�A �@)],
    [qw(�C �B)],
    [qw(�E �D ��)],
    [qw(�G �F)],
    [qw(�I �H)],
    [qw(�J �K ��)],
    [qw(�L �M)],
    [qw(�N �O)],
    [qw(�P �Q ��)],
    [qw(�R �S)],
    [qw(�T �U)],
    [qw(�V �W)],
    [qw(�X �Y)],
    [qw(�Z �[)],
    [qw(�\ �])],
    [qw(�^ �_)],
    [qw(�` �a)],
    [qw(�c �d)],
    [qw(�e �f)],
    [qw(�g �h)],
    [qw(�i)],
    [qw(�j)],
    [qw(�k)],
    [qw(�l)],
    [qw(�m)],
    [qw(�n �o �p)],
    [qw(�q �r �s)],
    [qw(�t �u �v)],
    [qw(�w �x �y)],
    [qw(�z �{ �|)],
    [qw(�})],
    [qw(�~)],
    [qw(��)],
    [qw(��)],
    [qw(��)],
    [qw(�� ��)],
    [qw(�� ��)],
    [qw(�� ��)],
    [qw(��)],
    [qw(��)],
    [qw(��)],
    [qw(��)],
    [qw(��)],
    [qw(�� �� �� �� ��)],
    [qw(�� ��)],
    [qw(�� ��)],
    [qw(�� ��)],
    [qw(�� ��)],
    [qw(�� ��)],
    [qw(�� ��)],
    [qw(�� ��)],
    [qw(�� ��)],
    [qw(�� ��)],
    [qw(�� ��)],
    [qw(�� ��)],
    [qw(�� ��)],
    [qw(�� ��)],
    [qw(�� ��)],
    [qw(�� ��)],
    [qw(�� ��)],
    [qw(�� ��)],
    [qw(�� ��)],
    [qw(�� ��)],
    [qw(�� ��)],
    [qw(��)],
    [qw(��)],
    [qw(��)],
    [qw(��)],
    [qw(��)],
    [qw(�� �� ��)],
    [qw(�� �� ��)],
    [qw(�� �� ��)],
    [qw(�� �� ��)],
    [qw(�� �� ��)],
    [qw(��)],
    [qw(��)],
    [qw(��)],
    [qw(��)],
    [qw(��)],
    [qw(�� ��)],
    [qw(�� ��)],
    [qw(�� ��)],
    [qw(��)],
    [qw(��)],
    [qw(��)],
    [qw(��)],
    [qw(��)],
    [qw(�� �� �� �� ��)],
  );
  $Index{KCharHash} = {};
  $Index{KCharLen} = length($kindextitle[0][0]);
  for my $chr(@kindextitle) {
    for my $ch(@$chr) {
      $Index{KCharHash}{$ch} = $chr->[0];
    }
  }
  sub indextitlechar {
    my($reading) = @_;
    my $result = ' ';
    my $ch;
    if( $reading =~ /^([A-Za-z])/ ) {
      $result = uc($1);
    } elsif( $ch = $Index{KCharHash}{substr($reading, 0, $Index{KCharLen})} ) {
      $result = $ch;
    }
    return $result;
  }
  $Index{TermText} = {};
</eval>

<!--
  <INDEX>�F��������w��
  �����Fterm=������
        reading=�ǂ݁i�A���t�@�x�b�g�A�Ђ炪�ȁA�J�^�J�i�j
        ��reading�̉p�啶���������͋�ʂ���Ȃ�
        ��term��reading�������ꍇ��reading���ȗ��ł���
  ���e�F�����Ƃ��ĉ���
-->
<def tag="INDEX" contentsmode="arg">
  <eval>
    $Args{reading} = $Args{term} if ($Args{reading} eq '' and !ref($Args{term}));
    $Args{reading} =~ tr/a-z/A-Z/;
    $Args{_dname} = 
      indextitlechar($Args{reading})."$;$Args{reading}$;$Args{term}";
    if( ref($Args{term}) ) {
      $Index{TermText}{$Args{term}} = $Args{term};
    }
  </eval>
  <return>
    <Dest name="$Args{_dname}"/>
  </return>
</def>

<!--
  <MAKEINDEX>�F�������쐬���A���̒i���̃��X�g��Ԃ�
  �����Fbeginindent=�y�[�W�ԍ��Q�̍s���C���f���g�i�ȗ����l50�j
        endindent=������̍s���C���f���g�i�ȗ����l50�j
        space=������ƃy�[�W�ԍ��Q�̊Ԃ̍ŏ��󔒃T�C�Y�i�ȗ����l20�j
        dot=������ƃy�[�W�ԍ��Q�̊Ԃ𖄂߂镶����i�ȗ����l"�d"�j
        title=�����ꓪ������\�����镶����i{title}�͓������ɒu���j�i�ȗ����l"�|{title}�|"�j
        defaulttitle=�p�������ȊO�ɑ΂�������ꓪ�������i�ȗ����l"�L���E����"�j
  ���e�F�����Ƃ��ĉ���
-->
<def tag="MAKEINDEX" contentsmode="arg" beginindent="50" endindent="50" 
  space="20" dot="�d" title="�|{title}�|" defaulttitle="�L���E����">
  <eval>
    $Args{_destnames} = [sort grep /$;/, $Doc->destnames];
    $Args{_lasttitle} = '';
    $Args{_altstyle} = {beginindent => $Args{beginindent}, endindent => 0,
      align => ['W', 'e']};
    $Args{_spaceglue} = [$Args{space} / $TStyle{default}{fontsize}, 
      $Args{space} / $TStyle{default}{fontsize}, 1000, 3];
    $Args{_spacestyle} = {filltext => $Args{dot}};
  </eval>
  <clone setvar="$Args{_pstyle}" caller="$PStyle{default}" 
    linefeed="120%" preskip="25%" postskip="25%" nobreak="1" align="b" 
    endindent="$Args{endindent}"/>
  <clone setvar="$Args{_titlepstyle}" caller="$PStyle{default}" align="m" 
    preskip="175%" postnobreak="1"/>
  <clone setvar="$Args{_tstyle}" caller="$TStyle{default}"/>
  <clone setvar="$Args{_titletstyle}" caller="$TStyle{default}" bold="1"/>
  <return>
    <for setvar="$Args{_dname}" eval="$Args{_destnames}">
      <eval>
        ($Args{_title}, $Args{_reading}, $Args{_term}) = split $;, $Args{_dname};
        $Args{_term} = $Index{TermText}{$Args{_term}} 
          if $Index{TermText}{$Args{_term}};
        $Args{_dpages} = $Doc->destpage($Args{_dname});
        $Args{_pagehash} = {};
        for my $pg(@{$Args{_dpages}}) {
          my $pn = $pg->[0]->pagenum;
          $Args{_pagehash}{$pn} = $pg unless $Args{_pagehash}{$pn};
        }
        $Args{_pagenums} = [sort {$a &lt;=&gt; $b} keys %{$Args{_pagehash}}];
      </eval>
      <do if="$Args{_title} ne $Args{_lasttitle}">
        <eval>
          $Args{_titletxt} = $Args{_title};
          $Args{_titletxt} = $Args{defaulttitle} if $Args{_titletxt} eq ' ';
          $Args{_titlestr} = $Args{title};
          $Args{_titlestr} =~ s/\{title\}/$Args{_titletxt}/g;
        </eval>
        <Paragraph style="$Args{_titlepstyle}">
          <text>
            <Text style="$Args{_titletstyle}" texts="$Args{_titlestr}"/>
          </text>
        </Paragraph>
        <eval>$Args{_lasttitle} = $Args{_title}</eval>
      </do>
      <Paragraph style="$Args{_pstyle}">
        <text>
          <Text style="$Args{_tstyle}">
            <texts>$Args{_term}</texts>
            <texts><Null style="$Args{_altstyle}"/></texts>
            <texts>
              <Space size="0" glue="$Args{_spaceglue}" 
                style="$Args{_spacestyle}"/>
            </texts>
            <texts>
              <eval>$Args{_needcomma} = 0</eval>
              <for setvar="$Args{_pagenum}" eval="$Args{_pagenums}">
                <eval>
                  $Args{_linkstyle} = {withbox => 'n', withboxstyle => 
                    {link => $Args{_pagehash}{$Args{_pagenum}}}};
                </eval>
                <do if="$Args{_needcomma}">
                  <Text texts=", ">
                    <style><TStyle/></style>
                  </Text>
                </do>
                <Text style="$Args{_linkstyle}" texts="$Args{_pagenum}"/>
                <eval>
                  $Args{_needcomma} = 1;
                </eval>
              </for>
            </texts>
          </Text>
        </text>
      </Paragraph>
    </for>
  </return>
</def>

</do>